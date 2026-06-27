#include <iostream>
using namespace std;

int main() {

    int m = 9;
    int a = 4;
    int c = 1;
    int r = 3; // semilla
    int semilla = r; 

// Generacion de la secuencia normalizada

    double xi = (double)r / m;
    
    cout << xi << endl; // imprime la semilla normalizada

    for (int i = 0; i < 8; i++) {
        r = (a*r + c) % m;
        double x = (double)r / m; // normalizacion de los demas numeros
        
        cout << x << endl;
    }

 // Escalamiento de los numeros al rango [10,20]   
    
    for (int i = 0; i < 9; i++){
        r = (a*r + c) % m;
        double x = (double)r / m;
        double escalado = 10 + (20-10) * x; // escalamiento de los numeros normalizados
        
        cout << escalado << endl; 
    }
   
// Secuencia lo mas grande posible (fijando M)
   
    r = semilla; // definimos la semilla

    int contador = 0;

    cout << "Secuencia:" << endl;
    
    cout << semilla << endl; // imprime la semilla

    do {
        r = (a * r + c) % m; // genera siguiente numero
        contador++; // contamos este nuevo valor

        cout << r << endl; // lo imprimimos

    } while (r != semilla); // se detiene cuando se repite

    cout << "Periodo: " << contador << endl;

 return 0;
}   
