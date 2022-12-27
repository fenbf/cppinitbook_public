// ex 2 4 most vexing parse error.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

struct Box { };

struct Product {
    Product(): name{"default product"} { }
    Product(const Box& b) : name{"box"}{ }
    std::string name;
};

int main() {
    Product p();
    std::cout << p.name;
    Product p2(Box());
    std::cout << p2.name;
}

