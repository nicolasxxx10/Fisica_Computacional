#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//==============================================================
// PARAMETROS DE LA FUNCION
//==============================================================

double A = 5.0;
double b = 3.0;

//==============================================================
// FUNCION
//==============================================================

double f(double x)
{
    return A * exp(-x/2.0) + b;
}

//==============================================================
// INTEGRAL EXACTA
//==============================================================

double integral_exacta(double x)
{
    return -2.0*A*exp(-x/2.0) + b*x;
}

//==============================================================
// METODO DE CAJAS
//==============================================================

double cajas(double a, double b_int, int n)
{
    double h = (b_int - a)/n;

    double suma = 0.0;

    for(int i=0; i<n; i++)
    {
        double x = a + i*h;

        suma += f(x);
    }

    return suma*h;
}

//==============================================================
// METODO DEL TRAPECIO
//==============================================================

double trapecio(double a, double b_int, int n)
{
    double h = (b_int - a)/n;

    double suma = (f(a) + f(b_int))/2.0;

    for(int i=1; i<n; i++)
    {
        double x = a + i*h;

        suma += f(x);
    }

    return suma*h;
}

//==============================================================
// METODO DE SIMPSON
//==============================================================

double simpson(double a, double b_int, int n)
{
    // Simpson requiere n par
    if(n%2 != 0)
        n++;

    double h = (b_int - a)/n;

    double suma = f(a) + f(b_int);

    for(int i=1; i<n; i++)
    {
        double x = a + i*h;

        if(i%2 == 0)
            suma += 2.0*f(x);
        else
            suma += 4.0*f(x);
    }

    return (h/3.0)*suma;
}

//==============================================================
// MAIN
//==============================================================

int main()
{
    double a = -1.0;
    double b_int = 1.0;

    //==========================================================
    // ARCHIVO DE SALIDA
    //==========================================================

    ofstream archivo("datos_integracionx.txt");

    archivo << fixed << setprecision(10);

    archivo << "#h exacta cajas trapecio simpson "
            << "error_cajas error_trapecio error_simpson\n";

    //==========================================================
    // INTEGRAL EXACTA
    //==========================================================

    double exacta =
        integral_exacta(b_int)
        -
        integral_exacta(a);

    cout << "Integral exacta = " << exacta << endl;

    //==========================================================
    // DISTINTOS VALORES DE h
    //==========================================================

    for(int n=10; n<=100; n+=10)
    {
        double h = (b_int - a)/n;

        double I_cajas = cajas(a,b_int,n);

        double I_trap = trapecio(a,b_int,n);

        double I_simp = simpson(a,b_int,n);

        //======================================================
        // ERRORES
        //======================================================

        double err_cajas =
            fabs(exacta - I_cajas);

        double err_trap =
            fabs(exacta - I_trap);

        double err_simp =
            fabs(exacta - I_simp);

        //======================================================
        // GUARDAR DATOS
        //======================================================

        archivo
        << h << " "
        << exacta << " "
        << I_cajas << " "
        << I_trap << " "
        << I_simp << " "
        << err_cajas << " "
        << err_trap << " "
        << err_simp << "\n";

    }

    archivo.close();

}
