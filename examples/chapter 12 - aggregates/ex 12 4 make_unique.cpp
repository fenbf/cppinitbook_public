// ex 12 3 make_unique.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <memory>

struct Point { int x; int y; };

int main() {
    auto ptr = std::make_unique<Point>(10, 20);
}

