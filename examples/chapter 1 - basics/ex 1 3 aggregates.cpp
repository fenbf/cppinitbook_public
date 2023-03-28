// ex 1 3 aggregates.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

struct Point { int x; int y; };
struct Line { Point p1; Point p2; };

int main() {
    // arrays:
    int arr[] { 1, 2, 3, 4 };
    float numbers[] = {0.1f, 1.1f, 2.2f, 3.f, 4.f, 5. };
    int nums[10] { 1 }; // 1, and then all 0s

    // structures:
    Line longLine {0, 0, 100, 100};
    Line anotherLine = {100}; // rest set to 0
    Line shortLine {{-10, -10}, {10, 10}}; // nested
}

