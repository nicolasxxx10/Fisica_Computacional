#include <iostream>
#include <fstream>
using namespace std;

int main(){

    long long a = 25214903917;
    long long c = 11;
    long long m = (1LL << 48);

    long long r = 10; // semilla

    ofstream archivo("datos_lcg.txt");

    int N = 100;

    for(int i = 0; i < N; i++){

        long long siguiente = (a * r + c) % m;

        archivo << r << " " << siguiente << endl;

        r = siguiente;
    }

    archivo.close();
    return 0;
}