#include <iostream>

int main() {
    std::string stars(40, '*');
    std::string moreStars{40, '*'}; // ??
    std::cout << stars << '\n';
    std::cout << moreStars << '\n';
}