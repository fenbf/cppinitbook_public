// ex 8 2 basics of initialization.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>

struct SimpleType {
    int field { 0 };
};

int main() {
    SimpleType st;
    std::cout << "st.field is " << st.field << '\n';
}

