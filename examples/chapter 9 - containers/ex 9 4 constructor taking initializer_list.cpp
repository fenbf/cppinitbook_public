// ex 9 4 constructor taking initializer_list.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <initializer_list>

struct X {
    X(std::initializer_list<int> list) 
    : count{list.size()} { puts("X(init_list)"); }
    X(size_t cnt) : count{cnt} { puts("X(cnt)"); }
    X() { puts("X()"); }
    size_t count {};
};

int main() {
    X x;
    std::cout << "x.count = " << x.count << '\n';
    X y { 1 };
    std::cout << "y.count = " << y.count << '\n';
    X z { 1, 2, 3, 4 };
    std::cout << "z.count = " << z.count << '\n';
    X w ( 3 );
    std::cout << "w.count = " << w.count << '\n';
}

