// ex 8 10 direct initialization and parens.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>

int main() {
    std::string stars(40, '*');
    std::string moreStars{40, '*'}; // ??
    std::cout << stars << '\n';
    std::cout << moreStars << '\n';
}

