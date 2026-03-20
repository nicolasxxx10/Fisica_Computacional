#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

int main(){

    // generador de numeros aleatorios
    mt19937 gen(time(0));

    // distribución uniforme entre 0 y 100
    uniform_int_distribution<int> dist(0, 100);

    ofstream archivo("datos_rand.txt");

    int N = 100;

    int x = dist(gen);

    for(int i = 0; i < N; i++){

        int y = dist(gen);

        archivo << x << " " << y << endl;

        x = y;
    }

    archivo.close();

    return 0;
}