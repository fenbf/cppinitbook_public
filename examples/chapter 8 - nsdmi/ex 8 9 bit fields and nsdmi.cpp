// ex 8 9 bit fields and nsdmi.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// Creative Commons Licence

#include <iostream>

struct Type {
    int value : 4 = 1;
    int second : 4 { 2 };
};

int main() {
    Type t;
    std::cout << t.value << '\n';
    std::cout << t.second << '\n';
}

