
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "DyH.h"

void QuickSort_First(std::vector<int>& v, int ini, int fin);
void QuickSort_Middle(std::vector<int>& v, int ini, int fin);
void QuickSort_Random(std::vector<int>& v, int ini, int fin);

int Partition_First(std::vector<int>& v, int ini, int fin);
int Partition_Middle(std::vector<int>& v, int ini, int fin);
int Partition_Random(std::vector<int>& v, int ini, int fin);

void testBusquedaInt_INV() {
    std::vector<int> v{20, 15, 10, 5, 0};
    int x = 10;
    int pos = BusquedaBinaria_INV(x, v, 0, v.size() - 1);
    std::cout << "[INT DESC] Posición de " << x << ": " << pos << std::endl;
}

void testBusquedaFloat() {
    std::vector<float> v{1.1, 2.2, 3.3, 4.4, 5.5};
    float x = 3.3;
    int pos = BusquedaBinaria_INV(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[FLOAT DESC] Posición de " << x << ": " << pos << std::endl;
}

void testBusquedaChar_INV() {
    std::vector<char> v{'z', 'x', 'v', 't', 'r'};
    char x = 'v';
    int pos = BusquedaBinaria_INV(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[CHAR DESC] Posición de '" << x << "': " << pos << std::endl;
}

void testQuickSortInt() {
    std::vector<int> v{9, 3, 7, 1, 5};
    QuickSort(v, 0, v.size() - 1);
    std::cout << "[QuickSort INT] Resultado: ";
    for (int val : v) std::cout << val << " ";
    std::cout << std::endl;
}

void testQuickSortFloat() {
    std::vector<float> v{4.4, 1.1, 3.3, 5.5, 2.2};
    std::vector<int> vi(v.begin(), v.end());
    QuickSort(vi, 0, vi.size() - 1);
    std::cout << "[QuickSort FLOAT] Resultado: ";
    for (int val : vi) std::cout << static_cast<float>(val) << " ";
    std::cout << std::endl;
}

void testQuickSortChar() {
    std::vector<char> v{'d', 'a', 'c', 'b', 'e'};
    std::vector<int> vi(v.begin(), v.end());
    QuickSort(vi, 0, vi.size() - 1);
    std::cout << "[QuickSort CHAR] Resultado: ";
    for (int val : vi) std::cout << static_cast<char>(val) << " ";
    std::cout << std::endl;
}

void QuickSort_First(std::vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition_First(v, ini, fin);
        QuickSort_First(v, ini, pivot - 1);
        QuickSort_First(v, pivot + 1, fin);
    }
}

int Partition_First(std::vector<int>& v, int ini, int fin) {
    std::swap(v[ini], v[fin]);
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

void QuickSort_Middle(std::vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition_Middle(v, ini, fin);
        QuickSort_Middle(v, ini, pivot - 1);
        QuickSort_Middle(v, pivot + 1, fin);
    }
}

int Partition_Middle(std::vector<int>& v, int ini, int fin) {
    int mid = (ini + fin) / 2;
    std::swap(v[mid], v[fin]);
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

void QuickSort_Random(std::vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition_Random(v, ini, fin);
        QuickSort_Random(v, ini, pivot - 1);
        QuickSort_Random(v, pivot + 1, fin);
    }
}

int Partition_Random(std::vector<int>& v, int ini, int fin) {
    int randIndex = ini + rand() % (fin - ini + 1);
    std::swap(v[randIndex], v[fin]);
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

void benchmarkQuickSort(const std::string& name, void (*sortFunc)(std::vector<int>&, int, int), std::vector<int> v) {
    auto start = std::chrono::system_clock::now();
    sortFunc(v, 0, v.size() - 1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << name << " Time: " << duration.count() << " ms" << std::endl;
}

int main() {
    testBusquedaInt_INV();
    testBusquedaFloat();
    testBusquedaChar_INV();
    testQuickSortInt();
    testQuickSortFloat();
    testQuickSortChar();

    std::vector<int> original;
    for (int i = 0; i < 10000; ++i) {
        original.push_back(rand() % 10000);
    }

    benchmarkQuickSort("QuickSort Last", QuickSort, original);
    benchmarkQuickSort("QuickSort First", QuickSort_First, original);
    benchmarkQuickSort("QuickSort Middle", QuickSort_Middle, original);
    benchmarkQuickSort("QuickSort Random", QuickSort_Random, original);

    return 0;
}
