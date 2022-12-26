#include <iostream>

struct Point { float x = 1.0f; float y = 2.0f; };

int main()
{
    Point myPt { 10.0f };
    std::cout << myPt.x << ", " << myPt.y << '\n';
}