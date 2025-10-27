
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
    int pos = BusquedaBinaria(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[FLOAT] Posición de " << x << ": " << pos << std::endl;
}


void testBusquedaChar_INV() {
    std::vector<char> v{'z', 'x', 'v', 't', 'r'};
    char x = 'v';
    int pos = BusquedaBinaria_INV(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[CHAR DESC] Posición de '" << x << "': " << pos << std::endl;
}


int main() {
    testBusquedaInt_INV();
    testBusquedaFloat();
    testBusquedaChar_INV();
    return 0;
}

