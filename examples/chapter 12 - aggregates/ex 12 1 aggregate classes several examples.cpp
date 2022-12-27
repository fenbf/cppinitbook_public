// ex 12 1 aggregate classes several examples.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <numeric>
#include <array>

struct Base { int x {42}; };
struct Derived : Base { int y; };

struct Param { 
    std::string name; 
    int val; 
    void Parse();  // member functions allowed
};

int main() {
    Derived d {100, 1000};    
    std::cout << "d.x " << d.x << ", d.y " << d.y << '\n';
    Derived d2 { 1 };
    std::cout << "d2.x " << d2.x << ", d2.y " << d2.y << '\n';
    Param p {"value", 10};
    std::cout << "p.name " << p.name << ", p.val " << p.val << '\n';

    double arr[] { 1.1, 2.2, 3.3, 4.4};
    std::cout << "arr[0] " << arr[0] << '\n';
    std::array floats { 10.1f, 20.2f, 30.3f };
    std::cout << "floats[0] " << floats[0] << '\n';
    std::array params {Param{"val", 10}, Param{"name", 42}};
    std::cout << "params[0].name " << params[0].name << '\n';
}

