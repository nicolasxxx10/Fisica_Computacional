#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

// Definimos un alias para hacer el código más limpio y legible
using Complex = std::complex<double>;

int main() {
    // 1. Señal discreta x = [1, 2, 3, 4]
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0};
    
    // 2. Número de muestras N = len(x)
    int N = x.size();
    
    // 3. Inicializar el vector para guardar el resultado (X = [])
    std::vector<Complex> X(N);
    
    const double PI = std::acos(-1.0); // Definición precisa de pi

    // 4. Calcular la DFT mediante bucles anidados
    for (int k = 0; k < N; ++k) {
        Complex sum(0.0, 0.0); // Equivalente a sum = 0
        
        for (int n = 0; n < N; ++n) {
            // Exponente de la fórmula de Fourier: -2 * pi * k * n / N
            double theta = -2.0 * PI * k * n / N;
            
            // Exponencial compleja e^(i*theta) = cos(theta) + i*sin(theta)
            Complex exp_term(std::cos(theta), std::sin(theta));
            
            // sum += x[n] * e^(i*theta)
            sum += x[n] * exp_term;
        }
        
        X[k] = sum; // Equivalente a X.append(sum)
    }

    // 5. Mostrar los resultados en pantalla
    std::cout << "Resultados de la DFT:\n";
    for (int k = 0; k < N; ++k) {
        std::cout << "X[" << k << "] = " 
                  << X[k].real() << " + " 
                  << X[k].imag() << "j\n";
    }

    return 0;
}