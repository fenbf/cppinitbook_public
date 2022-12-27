// ex 9 2 containers and nsdmi.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct S {
    int numbers[4] { 1, 2, 3, 4};
    // int nums[] { 0, 1, 2 }; // need to provide the size!
    std::array<double, 3> doubles { 0.1, 1.1, 2.1 };
    std::vector<int> ints { 100, 101, 102};
    std::vector<int> moreInts = std::vector<int>(10, 1);
    std::vector<std::string> names = std::vector<std::string>(10, "hello");
    std::map<std::string, int> mapping { {"one", 1}, {"two", 2} };
};

int main() {
    S s;
    std::cout << "s.numbers[0]: " << s.numbers[0] << '\n';
    std::cout << "s.double[0]: " << s.doubles[0] << '\n';
    std::cout << "s.ints[0]: " << s.ints[0] << '\n';
    std::cout << "s.moreInts[9]: " << s.moreInts[9] << '\n';
    std::cout << "s.names[9]: " << s.names[9] << '\n';
    std::cout << "s.mapping[\"one\"]: " << s.mapping["one"] << '\n';
}

