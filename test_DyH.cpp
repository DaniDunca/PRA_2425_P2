
#include <iostream>
#include <vector>
#include "DyH.h"


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
    std::cout << "[FLOAT] Posición de " << x << ": " << pos << std::endl;
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



int main() {
    testBusquedaInt_INV();
    testBusquedaFloat();
    testBusquedaChar_INV();
    testQuickSortInt();
    testQuickSortFloat();
    testQuickSortChar();
    return 0;
}

