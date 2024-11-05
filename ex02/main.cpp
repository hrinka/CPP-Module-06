#include "TypeIdentifier.hpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    delete obj;  // メモリリークを防ぐための削除

    return 0;
}
