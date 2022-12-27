// ex 2 5 multiple arguments and braces.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

struct Product {
    Product()
    : name{"default product"}
    , value{} 
    { }
    Product(char a, char b, char c, double v) 
        : name{a, b, c}
        , value{v} 
    { }
    
    std::string name;
    double value;
};

int main() {
    Product def{};    
    std::cout << def.name << ", " << def.value << '\n';
    Product p{'x', 'y', 'z', 100.0};
    std::cout << p.name << ", " << p.value;
}

