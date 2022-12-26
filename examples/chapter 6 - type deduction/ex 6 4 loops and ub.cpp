#include <vector>
#include <iostream>

auto getVec() {
    std::vector<std::vector<int>> ints { {1, 2}, {3, 4}, {5, 6} };
    return ints;
}

int main() {
    for (auto& i : getVec()[1])
        std::cout << i;
}