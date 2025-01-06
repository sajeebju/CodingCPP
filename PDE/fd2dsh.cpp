#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

const double xmax = 500.0;
const double zmax = xmax;
const double tmax = 0.502;
const double vs0 = 580.0;
const double rho0 = 1000.0;
const double xr = 330.0;
const double zr = xr;
const double xsrc = 250.0;
const double zsrc = 250.0;
const double f0 = 40.0;
const double t0 = 4.0 / f0;


void update_vel(std::vector<std::vector<double>> &vy,
                const std::vector<std::vector<double>> &syx,
                const std::vector<std::vector<double>> &syz,
                double dx, double dz, double dt, int nx, int nz,
                const std::vector<std::vector<double>> &rho) {
    for (int i = 1; i < nx - 1; ++i) {
        for (int j = 1; j < nz - 1; ++j) {
            double syx_x = (syx[i][j] - syx[i - 1][j]) / dx;
            double syz_z = (syz[i][j] - syz[i][j - 1]) / dz;
            vy[i][j] += (dt / rho[i][j]) * (syx_x + syz_z);
        }
    }
}


void update_stress(std::vector<std::vector<double>> &syx,
                   std::vector<std::vector<double>> &syz,
                   const std::vector<std::vector<double>> &vy,
                   double dx, double dz, double dt, int nx, int nz,
                   const std::vector<std::vector<double>> &mux,
                   const std::vector<std::vector<double>> &muz) {
    for (int i = 1; i < nx - 1; ++i) {
        for (int j = 1; j < nz - 1; ++j) {
            double vy_x = (vy[i + 1][j] - vy[i][j]) / dx;
            double vy_z = (vy[i][j + 1] - vy[i][j]) / dz;
            syx[i][j] += dt * mux[i][j] * vy_x;
            syz[i][j] += dt * muz[i][j] * vy_z;
        }
    }
}


void shear_avg(const std::vector<std::vector<double>> &mu, int nx, int nz,
               std::vector<std::vector<double>> &mux,
               std::vector<std::vector<double>> &muz) {
    for (int i = 1; i < nx - 1; ++i) {
        for (int j = 1; j < nz - 1; ++j) {
            mux[i][j] = 2.0 / (1.0 / mu[i + 1][j] + 1.0 / mu[i][j]);
            muz[i][j] = 2.0 / (1.0 / mu[i][j + 1] + 1.0 / mu[i][j]);
        }
    }
}


void FD_2D_SH(double dt, double dx, double dz) {
    int nx = static_cast<int>(xmax / dx);
    int nz = static_cast<int>(zmax / dz);
    int nt = static_cast<int>(tmax / dt);

    int ir = static_cast<int>(xr / dx);
    int jr = static_cast<int>(zr / dz);
    int isrc = static_cast<int>(xsrc / dx);
    int jsrc = static_cast<int>(zsrc / dz);

    std::vector<double> src(nt, 0.0);
    for (int it = 0; it < nt; ++it) {
        double time = it * dt;
        src[it] = -2.0 * (time - t0) * (f0 * f0) * std::exp(-f0 * f0 * (time - t0) * (time - t0));
    }

    std::vector<std::vector<double>> vy(nx, std::vector<double>(nz, 0.0));
    std::vector<std::vector<double>> syx(nx, std::vector<double>(nz, 0.0));
    std::vector<std::vector<double>> syz(nx, std::vector<double>(nz, 0.0));
    std::vector<std::vector<double>> rho(nx, std::vector<double>(nz, rho0));
    std::vector<std::vector<double>> vs(nx, std::vector<double>(nz, vs0));

    std::vector<std::vector<double>> mu(nx, std::vector<double>(nz, 0.0));
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < nz; ++j) {
            mu[i][j] = rho[i][j] * vs[i][j] * vs[i][j];
        }
    }

    std::vector<std::vector<double>> mux = mu;
    std::vector<std::vector<double>> muz = mu;
    shear_avg(mu, nx, nz, mux, muz);

    std::vector<double> seis(nt, 0.0);

    for (int it = 0; it < nt; ++it) {
        update_vel(vy, syx, syz, dx, dz, dt, nx, nz, rho);
        vy[isrc][jsrc] += (dt * src[it]) / (rho[isrc][jsrc] * dx * dz);
        update_stress(syx, syz, vy, dx, dz, dt, nx, nz, mux, muz);
        seis[it] = vy[ir][jr];
    }

    std::ofstream outfile("seismogram.txt");
    if (outfile.is_open()) {
        for (int it = 0; it < nt; ++it) {
            outfile << it * dt << " " << seis[it] << "\n";
        }
        outfile.close();
        std::cout << "Seismogram saved to seismogram.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }
}

int main() {
    double dx = 1.0;
    double dz = 1.0;
    double dt = 0.001;

    FD_2D_SH(dt, dx, dz);

    return 0;
}
