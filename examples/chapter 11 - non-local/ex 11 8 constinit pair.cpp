// ex 11 8 constinit pair.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <utility>

constinit std::pair<int, double> global { 42, 42.2 };
constexpr std::pair<int, double> constG { 42, 42.2 };

int main() {
    std::cout << global.first << ", " << global.second << '\n';
    // but allow to change later...
    global = { 10, 10.1 };
    std::cout << global.first << ", " << global.second << '\n';
    // constG = { 10, 10.1 }; // not allowed, const
}

