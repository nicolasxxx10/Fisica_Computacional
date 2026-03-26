#include <iostream>
#include <fstream>
using namespace std; 

int main (){

    int m = 256;
    int a = 57;
    int c = 1;
    int r = 10; // semilla
    int semilla = r;


    cout << r << endl; // imprime la semilla 

    for(int i = 0; i < 255; i++){
        r = (a*r + c) % m;

        cout << r << endl; // imprime los demas numeros
    }
  
// Periodo de la secuencia 
   
    r = semilla; // definimos la semilla

    int contador = 0;

    do {
        r = (a * r + c) % m; // genera siguiente número
        contador++; // contamos este nuevo valor

    } while (r != semilla); // se detiene cuando se repite

    cout << "Periodo: " << contador << endl;


// Guardar los datos para graficar

ofstream archivo("datos_p.txt");

for(int i = 0; i < 255; i++){
      
    int siguiente = (a*r + c) % m;

    archivo << r << " " << siguiente << endl;
    r = siguiente;

}   

archivo.close();

return 0;

}



    