#include <vector>
#include <iostream>

using Matrix = std::vector<std::vector<T>>;

template<typename T>
Matrix<T> update_vel(Matrix<T>& vy, const Matrix<T>& syx, const Matrix<T>& syz, T dx, T dz, T dt, int nx, int nz, const Matrix<T>& rho) {
    #pragma omp parallel for collapse(2) 
    for (int i = 1; i < nx - 1; i++) {
        for (int j = 1; j < nz - 1; j++) {
            T syx_x = (syx[i][j] - syx[i - 1][j]) / dx;
            T syz_z = (syz[i][j] - syz[i][j - 1]) / dz;

            vy[i][j] = vy[i][j] + (dt / rho[i][j]) * (syx_x + syz_z);
        }
    }
    return vy;
}

template<typename T>
void update_stress(Matrix<T>& vy, Matrix<T>& syx, Matrix<T>& syz, T dx, T dz, T dt, int nx, int nz, const Matrix<T>& mux, const Matrix<T>& muz) {
    #pragma omp parallel for collapse(2) 
    for (int i = 1; i < nx - 1; i++) {
        for (int j = 1; j < nz - 1; j++) {
            T vy_x = (vy[i + 1][j] - vy[i][j]) / dx;
            T vy_z = (vy[i][j + 1] - vy[i][j]) / dz;
            
            syx[i][j] = syx[i][j] + dt * mux[i][j] * vy_x;
            syz[i][j] = syz[i][j] + dt * muz[i][j] * vy_z;
        }
    }
}

template<typename T>
void shear_avg(const std::vector<std::vector<T>>& mu, 
               int nx, int nz, 
               std::vector<std::vector<T>>& mux, 
               std::vector<std::vector<T>>& muz) {
    
    for (int i = 1; i < nx - 1; ++i) {
        for (int j = 1; j < nz - 1; ++j) {
            // Calculate harmonic averages of shear moduli
            mux[i][j] = 2 / (1 / mu[i + 1][j] + 1 / mu[i][j]);
            muz[i][j] = 2 / (1 / mu[i][j + 1] + 1 / mu[i][j]);
        }
    }
}

template<typename T>
std::vector<T> FD_2D_SH(T dt, T dx, T dz, T f0, T xsrc, T zsrc, T xmax, T zmax, T tmax, T xr, T zr, T vs0, T rho0) {
    int nx = static_cast<int>(xmax / dx);
    int nz = static_cast<int>(zmax / dz);
    int nt = static_cast<int>(tmax / dt);
    int ir = static_cast<int>(xr / dx);
    int jr = static_cast<int>(zr / dz);
    int isrc = static_cast<int>(xsrc / dx);
    int jsrc = static_cast<int>(zsrc / dz);

    std::vector<T> src(nt + 1, 0.0);
    for (int it = 0; it < nt; ++it) {
        T time = it * dt;
        src[it] = -2.0 * (time - f0) * (f0 * f0) * exp(-f0 * f0 * (time - f0) * (time - f0));
    }

    Matrix<T> vy(nx, std::vector<T>(nz, 0.0));
    Matrix<T> syx(nx, std::vector<T>(nz, 0.0));
    Matrix<T> syz(nx, std::vector<T>(nz, 0.0));
    Matrix<T> rho(nx, std::vector<T>(nz, rho0));
    Matrix<T> vs(nx, std::vector<T>(nz, vs0));
    Matrix<T> mu(nx, std::vector<T>(nz, rho0 * vs0 * vs0));
    Matrix<T> mux(nx, std::vector<T>(nz));
    Matrix<T> muz(nx, std::vector<T>(nz));

    shear_avg(mu, nx, nz, mux, muz);

    std::vector<T> seis(nt, 0.0);

    for (int it = 0; it < nt; ++it) {
        update_vel(vy, syx, syz, dx, dz, dt, nx, nz, rho);

        vy[isrc][jsrc] += dt * src[it] / (rho[isrc][jsrc] * dx * dz);

        update_stress(vy, syx, syz, dx, dz, dt, nx, nz, mux, muz);

        seis[it] = vy[ir][jr];
    }

    return seis;
}



