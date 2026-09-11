#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

int busquedaLineal(const vector<int>& a, const int valor) {
    for (int i=0; i<a.size(); i++) { // Va uno por uno hasta que encuentre el valor
        if (a[i] == valor) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(const vector<int>& a, const int valor) {
    int s = 0;
    int e = a.size()-1;
    while (s <= e) {
        int m = s + ((e-s)/2); // Calcula un punto medio
        if (a[m] == valor) return m; // Caso base

        // Ajuste de limites del vector
        if (a[m] < valor) s = m + 1;
        else e = m - 1;
    }
    return -1;
}

int busquedaTrinaria(const vector<int>& a, const int valor) {
    int s = 0;
    int e = a.size()-1;

    while (s <= e) {
        // Calculo de puntos medios
        int m1 = s + ((e-s)/3);
        int m2 = e - ((e-s)/3);

        // Casos base
        if (a[m1] == valor) return m1;
        if (a[m2] == valor) return m2;

        // Encuentra la mitad donde se encuentra el valor
        if (a[m1] > valor) {
            e = m1 - 1;
        } else if (a[m2] < valor) {
            s = m2 + 1;
        } else {
            s = m1 + 1;
            e = m2 - 1;
        }
    }
    return -1;
}

vector<int> generarVector(size_t tamano, int min, int max) {
    vector<int> vec(tamano);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(min,max);

    for (size_t i = 0; i < tamano; i++) {
        vec[i] = distribucion(gen);
    }
    sort(vec.begin(), vec.end());
    return vec;
}

void calcularTiempo(const string& etiquetaTamano, const int tamanoVector) {
    cout << "\n--Tamano " << etiquetaTamano << endl;

    mt19937 gen(random_device{}()); // Para buscar un valor aleatorio
    uniform_int_distribution<int> valor(1, 1000000000);

    chrono::duration<double, micro> duracionTotalLineal{0};
    chrono::duration<double, micro> duracionTotalBinaria{0};
    chrono::duration<double, micro> duracionTotalTrinaria{0};
    for (int i = 0; i < 30; i++) {
        // Declaracion de vectores

        vector<int> vec = generarVector(tamanoVector, 1, tamanoVector);
        int v = valor(gen);

        auto inicioLineal = chrono::high_resolution_clock::now();
        busquedaLineal(vec, v);
        auto finLineal = chrono::high_resolution_clock::now();

        auto inicioBinaria = chrono::high_resolution_clock::now();
        busquedaBinaria(vec, v);
        auto finBinaria = chrono::high_resolution_clock::now();

        auto inicioTrinaria = chrono::high_resolution_clock::now();
        busquedaTrinaria(vec, v);
        auto finTrinaria = chrono::high_resolution_clock::now();

        duracionTotalLineal += (finLineal-inicioLineal);
        duracionTotalBinaria += (finBinaria-inicioBinaria);
        duracionTotalTrinaria += (finTrinaria-inicioTrinaria);
    }
    cout << "Busqueda Lineal" << endl;
    cout << "Tiempo total: " << duracionTotalLineal.count() << " microsegundos\n" << "Tiempo promedio: " << duracionTotalLineal.count() / 30 << " microsegundos" << endl;
    cout << "Busqueda Binaria" << endl;
    cout << "Tiempo total: " << duracionTotalBinaria.count() << " microsegundos\n" << "Tiempo promedio: " << duracionTotalBinaria.count() / 30 << " microsegundos" << endl;
    cout << "Busqueda Trinaria" << endl;
    cout << "Tiempo total: " << duracionTotalTrinaria.count() << " microsegundos\n" << "Tiempo promedio: " << duracionTotalTrinaria.count() / 30 << " microsegundos" << endl;
}

int main() {
    calcularTiempo("10^5", 100000);
    calcularTiempo("10^6",1000000);
    calcularTiempo("10^7",10000000);
    calcularTiempo("10^8",100000000);
    return 0;
}
