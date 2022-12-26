#include <iostream>
#include <vector>

struct Point { int x; int y; };

int main() {
    std::vector<Point> points;
    points.emplace_back(10, 20);
}