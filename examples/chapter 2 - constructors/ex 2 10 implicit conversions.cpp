// ex 2 10 implicit conversions.cpp
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
    Product(double v) 
        : name{"basic"}
        , value{v} 
    { }
    Product(const std::string& n, double v) 
        : name{n}
        , value{v} 
    { }
    
    std::string name;
    double value;
};

void printProduct(const Product& prod) {
    std::cout << prod.name << ", " << prod.value << '\n';
}

int main() {
    int someRandomNumber = 100;
    printProduct(someRandomNumber);
    printProduct({"a box", 2});
}

