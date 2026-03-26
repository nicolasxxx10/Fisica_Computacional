#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

int main() {

    // Archivos de salida
    std::ofstream datos("datos.txt");
    std::ofstream trayectoria("trayectoria.txt");

    // Generador aleatorio
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    int K = 1000;  // numero de caminatas
    int N_values[] = {10, 100, 1000, 5000};

    // Parte 1: calcular R_rms
    for(int n_index = 0; n_index < 4; n_index++) {

        int N = N_values[n_index];
        double suma_R2 = 0.0;

        for(int k = 0; k < K; k++) {

            double x = 0.0, y = 0.0;

            for(int i = 0; i < N; i++) {
                x += dis(gen);
                y += dis(gen);
            }

            suma_R2 += (x*x + y*y);
        }

        double Rrms = std::sqrt(suma_R2 / K);

        datos << N << " " << Rrms << std::endl;
    }

    // Parte 2: generar UNA trayectoria
    double x = 0.0, y = 0.0;

    for(int i = 0; i < 1000; i++) {
        x += dis(gen);
        y += dis(gen);
        trayectoria << x << " " << y << std::endl;
    }

    datos.close();
    trayectoria.close();

    return 0;
}