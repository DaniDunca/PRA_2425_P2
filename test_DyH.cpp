
#include <iostream>
#include <vector>
#include "DyH.h"

void testBusquedaInt() {
    std::vector<int> v{2, 4, 6, 8, 10};
    int x = 6;
    int pos = BusquedaBinaria(x, v, 0, v.size() - 1);
    std::cout << "[INT] Posición de " << x << ": " << pos << std::endl;
}

void testBusquedaFloat() {
    std::vector<float> v{1.1, 2.2, 3.3, 4.4, 5.5};
    float x = 3.3;
    int pos = BusquedaBinaria(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[FLOAT] Posición de " << x << ": " << pos << std::endl;
}

void testBusquedaChar() {
    std::vector<char> v{'a', 'c', 'e', 'g', 'i'};
    char x = 'e';
    int pos = BusquedaBinaria(static_cast<int>(x), std::vector<int>(v.begin(), v.end()), 0, v.size() - 1);
    std::cout << "[CHAR] Posición de '" << x << "': " << pos << std::endl;
}

int main() {
    testBusquedaInt();
    testBusquedaFloat();
    testBusquedaChar();
    return 0;
}

