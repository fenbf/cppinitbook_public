// ex 8 6 copy constructors and nsdmi.cpp
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
    
    SimpleType(const SimpleType& other) {
        std::cout << "copy ctor\n";
        
        a = other.a;
        b = other.b;
    };

};

int main() {
    SimpleType t1;
    std::cout << "SimpleType t2 = t1:\n";
    SimpleType t2 = t1;
}

