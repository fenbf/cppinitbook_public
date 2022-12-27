// ex 13 1 strong types.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>


constexpr double ToWattsRatio { 745.699872 };

class HorsePower;

class WattPower {
public:
    WattPower() = default;
    explicit WattPower(double p) : power_{p} { }
    explicit WattPower(const HorsePower& h);

    double getValue() const { return power_; }
private:
    double power_ {0.};
};

class HorsePower {
public:
    HorsePower() = default;
    explicit HorsePower(double p) : power_{p} { }
    explicit HorsePower(const WattPower& w);

    double getValue() const { return power_; }
private:
    double power_ {0.};
};

WattPower::WattPower(const HorsePower& h) 
: power_{h.getValue()*ToWattsRatio} 
{ }

HorsePower::HorsePower(const WattPower& w) 
: power_{w.getValue()/ToWattsRatio} 
{ }

std::ostream& operator<<(std::ostream& os, const WattPower& w) {
    os << w.getValue() << "W";
    return os;
}

std::ostream& operator<<(std::ostream& os, const HorsePower& h) {
    os << h.getValue() << "hp";
    return os;
}

struct CarInfo {
    std::string name;
    unsigned year;
    unsigned seats;
    HorsePower power;
};

void printInfo(const CarInfo& c) {
    std::cout << c.name << ", "
              << c.year << " year, "
              << c.seats << " seats, "
              << c.power << '\n';
}

int main() {
    CarInfo firstCar{"Megane", 2003, 5, HorsePower{116}};
    printInfo(firstCar);   
    CarInfo superCar{"Ferrari", 2022, 2, HorsePower{300}};
    printInfo(superCar);
    superCar.power = HorsePower{WattPower{500000}};
    printInfo(superCar);
}

