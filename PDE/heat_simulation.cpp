#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <omp.h>

template <typename T>
class HeatEquation2D{
public:
    HeatEquation2D(size_t nx, size_t ny, T dx, T dy, T dt, T alpha)
    : nx_(nx), ny_(ny), dx_(dx), dy_(dy), dt_(dt), alpha_(alpha),
        u_(nx, std::vector<T>(ny, 0)), u_new_(nx, std::vector<T>(ny, 0)){}

        void set_initial_condition(T value){
            for(size_t i = 0; i < nx_; ++i){
                for(size_t j = 0; j < ny_; j++){
                    u_[i][j] = value;
                }
            }
        }

        void set_heat_source(size_t x, size_t y, T value){
            u_[x][y] = value;
        }

        void time_step(){
            #pragma omp parallel for collapse(2)
            for(size_t i = 1; i < nx_ - 1; ++i){
                for(size_t j = 1; j < ny_ - 1; ++j){
                    T d2udx2 = u_[i+1][j] - 2* u_[i][j] + u_[i-1][j] / (dx_ * dx_);
                    T d2udy2 = u_[i][j+1] - 2* u_[i][j] + u_[i][j-1] / (dy_*dy_);
                    u_new_[i][j] = u_[i][j] + dt_ * alpha_ * (d2udx2 + d2udy2);
                }
            }
        }

        #pragma omp parallel for
        for (size_t i = 0; i < nx_; ++i) {
            u_new_[i][0] = u_new_[i][1];
            u_new_[i][ny_ - 1] = u_new_[i][ny_ - 2];
        }

        #pragma omp parallel for
        for (size_t j = 0; j < ny_; ++j) {
            u_new_[0][j] = u_new_[1][j];
            u_new_[nx_ - 1][j] = u_new_[nx_ - 2][j];
        }

        u_.swap(u_new_);
    }
    void run_simulation(size_t steps) {
        for (size_t step = 0; step < steps; ++step) {
            time_step();
        }
    }

    void print() const {
        for (size_t i = 0; i < nx_; ++i) {
            for (size_t j = 0; j < ny_; ++j) {
                std::cout << std::fixed << std::setprecision(2) << u_[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

private:
    size_t nx_, ny_;
    T dx_, dy_, dt_, alpha_;
    std::vector<std::vector<T>> u_, u_new_;
};

int main() {
    size_t nx = 100;
    size_t ny = 100;
    double dx = 0.02;
    double dy = 0.02;
    double dt = 0.0001;
    double alpha = 0.01;

    HeatEquation2D<double> heat_solver(nx, ny, dx, dy, dt, alpha);

    heat_solver.set_initial_condition(0.0);
    heat_solver.set_heat_source(nx / 2, ny / 2, 100.0);

    size_t time_steps = 500;

    auto start = std::chrono::high_resolution_clock::now();

    heat_solver.run_simulation(time_steps);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Final temperature distribution:\n";
    heat_solver.print();

    std::cout << "\nSimulation completed in " << elapsed.count() << " seconds.\n";

    return 0;
}
