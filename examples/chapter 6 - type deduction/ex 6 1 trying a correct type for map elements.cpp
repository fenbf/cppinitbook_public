// ex 6 1 trying a correct type for map elements.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m { {"hello", 1}, {"world", 2}};

    for (const std::pair<std::string, int>& elem : m)
        std::cout << elem.first << ", " << &elem.first << '\n';

    std::cout << m.begin()->first << ", " << std::addressof(m.begin()->first) << '\n';
    std::cout << std::next(m.begin())->first << ", " << std::addressof(std::next(m.begin())->first) << '\n';
}

