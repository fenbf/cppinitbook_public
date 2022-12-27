// ex 9 1 basic syntax.cpp
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
    S() 
    : numbers { 1, 2, 3, 4} 
    //, nums { 1, 2, 3}
    , doubles { 0.1, 1.1, 2.1 }
    , ints { 100, 101, 102}
    , moreInts( 10, 1) // 10 1's, not 10 and 1
    , names ( 10, "hello" ) // 10 "hello" strings
    , mapping { {"one", 1}, {"two", 2} }
    { }

    int numbers[4];
    // int nums[]; // need to provide the size!
    std::array<double, 3> doubles;
    std::vector<int> ints;
    std::vector<int> moreInts;
    std::vector<std::string> names;
    std::map<std::string, int> mapping;
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

