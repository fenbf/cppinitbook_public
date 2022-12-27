// ex 8 7 move constructors and nsdmi.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

int initA() {
    std::cout << "initA() called\n";
    return 1;
}

std::string initB() {
    std::cout << "initB() called\n";
    return "World";
}

struct SimpleType {        
    int a { initA() }; 
    std::string b { initB() };

    SimpleType() { }
    explicit SimpleType(std::string s) : b(std::move(s)) { }
    
    SimpleType(const SimpleType& other) = default;

    SimpleType(SimpleType&& other) 
    {
        std::cout << "move ctor\n";
        
        a = std::move(other.a);
        b = std::move(other.b);
    };
};

int main() {
    std::cout << "SimpleType t1:\n";    
    SimpleType t1;
    std::cout << "SimpleType t2 = t1:\n";
    SimpleType t2 = std::move(t1);
}

