// ex 1 2 setting to zero.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

struct CarInfo {
    std::string name;
    unsigned year;
    unsigned seats;
    double power;
};

int main() {
    CarInfo emptyCar{};
    std::cout << "name: " << emptyCar.name << '\n';
    std::cout << "year: " << emptyCar.year << '\n';
    std::cout << "seats: " << emptyCar.seats << '\n';
    std::cout << "power (hp): " << emptyCar.power << '\n';
}

