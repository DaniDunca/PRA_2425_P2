
#ifndef DYV_H
#define DYV_H
#include <vector>
#include <iostream>

int BusquedaBinaria_INV (int x, const std::vector<int> &v, int ini, int fin);
void QuickSort(std::vector<int>& v, int ini, int fin);
int Partition(std::vector<int>& v, int ini, int fin);


int BusquedaBinaria_INV(int x, const std::vector<int>& v, int ini, int fin) {
    if (ini > fin) {
        std::cout << "No se encuentra en el array" << std::endl;
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) return medio;
    else if (v[medio] < x) return BusquedaBinaria_INV(x, v, ini, medio - 1);
    else return BusquedaBinaria_INV(x, v, medio + 1, fin);
}


void QuickSort(std::vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(v, ini, fin);
        QuickSort(v, ini, pivot - 1);
        QuickSort(v, pivot + 1, fin);
    }
}


int Partition(std::vector<int>& v, int ini, int fin) {
    int x = v[fin];
    int i = ini;
    for (int j = ini; j < fin; ++j) {
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            ++i;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

#endif 

