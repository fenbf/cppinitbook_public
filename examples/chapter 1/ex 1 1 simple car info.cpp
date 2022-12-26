#include <iostream>
#include <string>

struct CarInfo {
    std::string name;
    unsigned year;
    unsigned seats;
    double power;
};

int main() {
    CarInfo firstCar;
    firstCar.name = "Renault Megane"; 
    firstCar.year = 2002;
    firstCar.seats = 5;
    firstCar.power = 116;
    std::cout << "name: " << firstCar.name << '\n';
    std::cout << "year: " << firstCar.year << '\n';
    std::cout << "seats: " << firstCar.seats << '\n';
    std::cout << "power (hp): " << firstCar.power << '\n';
}