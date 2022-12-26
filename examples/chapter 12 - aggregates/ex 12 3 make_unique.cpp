#include <iostream>
#include <memory>

struct Point { int x; int y; };

int main() {
    auto ptr = std::make_unique<Point>(10, 20);
}