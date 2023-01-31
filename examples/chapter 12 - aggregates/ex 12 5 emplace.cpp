// ex 12 4 emplace.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <vector>

struct Point { int x; int y; };

int main() {
    std::vector<Point> points;
    points.emplace_back(10, 20);
}

