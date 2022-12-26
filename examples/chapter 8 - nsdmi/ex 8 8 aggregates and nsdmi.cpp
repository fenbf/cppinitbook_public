// ex 8 8 aggregates and nsdmi.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// Creative Commons Licence

#include <iostream>

struct Point { float x = 1.0f; float y = 2.0f; };

int main()
{
    Point myPt { 10.0f };
    std::cout << myPt.x << ", " << myPt.y << '\n';
}

