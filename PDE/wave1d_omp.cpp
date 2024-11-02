#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <omp.h>

const int nx = 100;
const double dx = 0.1;
const int nt = 300;
const double dt = 0.001;
const double v = 3.0;

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<double> p(nx, 0.0);
    std::vector<double> p_new(nx, 0.0);
    std::vector<double> p_old(nx, 0.0);

    for (int it = 0; it < nt; ++it) {
        double source = (it == 50) ? 1.0 : 0.0;
        p[nx / 2] += source;

        #pragma omp parallel for
        for (int i = 1; i < nx - 1; ++i) {
            p_new[i] = 2 * p[i] - p_old[i] + (v * dt / dx) * (v * dt / dx) * (p[i + 1] - 2 * p[i] + p[i - 1]);
        }

        p_old = p;
        p = p_new;

        if (it % 50 == 0) {
            #pragma omp critical
            {
                for (int i = 0; i < nx; ++i) {
                    std::cout << i * dx << " " << p[i] << "\n";
                }
                std::cout << "\n";
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    std::cout << "Execution time: " << elapsed_seconds.count() << " seconds.\n";
    return 0;
}

