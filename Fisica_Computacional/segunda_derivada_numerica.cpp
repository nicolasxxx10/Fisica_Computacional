#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Definicion de la funcion coseno
double f(double x) {
    return cos(x);
}

// Segunda derivada analitica
double d2f_analitica(double x) {
    return -cos(x);
}

// Segunda derivada numerica 
double d2f_numerica(double x, double h) {
    return ( (f(x + h) -2*f(x) + f(x - h)) / pow(h,2) );
}


int main() {
    
    double h =1.0;

    ofstream archivo_der("derivada.txt");
    ofstream archivo_error("error.txt");

    for(double x = -5; x<=5; x+=0.1){
        double derivada_ana = d2f_analitica(x);
        double derivada_num = d2f_numerica(x,h);

        double error = abs(derivada_ana - derivada_num);    

        archivo_der << x << " " << derivada_ana << " " << derivada_num << endl; 
        archivo_error << x << " " << error << endl;

    }
archivo_der.close();
archivo_error.close();    

// Error maximo para diferentes tamaños de paso  

    double h_values [] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    
    ofstream archivo_errores("errores_h.txt");

    for(double h : h_values){

    double error_max = 0;

    for(double x=-5; x<=5; x+=0.1){

        double derivada_ana = d2f_analitica(x);

        double derivada_num = d2f_numerica(x,h);

        double error = abs(derivada_ana - derivada_num);

        if(error > error_max){
            error_max = error;
        }
    }

    archivo_errores << h << " " << error_max << endl;

    }
}