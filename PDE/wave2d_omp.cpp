#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include <cstdio> // for popen

const int nx = 100;
const int ny = 100;
const double dx = 0.1;
const double dy = 0.1;
const int nt = 300;
const double dt = 0.001;
const double v = 3.0;
const int source_x = nx / 2;
const int source_y = ny / 2;
const double frequency = 5.0;

double ricker_wavelet(double f, double t) {
    double a = (M_PI * f * (t - 1.0 / f)) * (M_PI * f * (t - 1.0 / f));
    return (1 - 2 * a) * std::exp(-a);
}

void plot_wavefield(const std::vector<std::vector<double>>& wavefield, int timestep) {
    std::ostringstream filename;
    filename << "wavefield_" << std::setw(3) << std::setfill('0') << timestep << ".dat";
    std::ofstream file(filename.str());
    
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            file << i * dx << " " << j * dy << " " << wavefield[i][j] << "\n";
        }
        file << "\n"; // Separate each row for gnuplot
    }
    file.close();

    std::string command = "gnuplot -e \"set view 50, 30; set pm3d; set xlabel 'X (km)'; set ylabel 'Y (km)'; set zlabel 'Pressure'; splot '" + filename.str() + "' with pm3d; pause -1\"";
    std::system(command.c_str());
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<double>> p(nx, std::vector<double>(ny, 0.0));
    std::vector<std::vector<double>> p_new(nx, std::vector<double>(ny, 0.0));
    std::vector<std::vector<double>> p_old(nx, std::vector<double>(ny, 0.0));

    for (int it = 0; it < nt; ++it) {
        double t = it * dt;
        double source = ricker_wavelet(frequency, t);
        p[source_x][source_y] += source;

        #pragma omp parallel for collapse(2)
        for (int i = 1; i < nx - 1; ++i) {
            for (int j = 1; j < ny - 1; ++j) {
                p_new[i][j] = 2 * p[i][j] - p_old[i][j]
                    + (v * dt / dx) * (v * dt / dx) * (p[i + 1][j] - 2 * p[i][j] + p[i - 1][j])
                    + (v * dt / dy) * (v * dt / dy) * (p[i][j + 1] - 2 * p[i][j] + p[i][j - 1]);
            }
        }

        p_old = p;
        p = p_new;

        if (it == 50 || it == 100 || it == 150 || it == 200 || it == 250) {
            plot_wavefield(p, it);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << "Simulation complete. Execution time: " << elapsed_seconds.count() << " seconds.\n";
    return 0;
}

