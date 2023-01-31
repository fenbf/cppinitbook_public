// ex 12 5 designated init demo.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

struct Product {
    std::string name_;
    bool inStock_ { false };
    double price_ = 0.0;
};

void Print(const Product& p) {
    std::cout << "name: " << p.name_ << ", in stock: "
              << std::boolalpha << p.inStock_ << ", price: " 
              << p.price_ << '\n';
}

struct Time { int hour; int minute; };
struct Date { Time t; int year; int month; int day; };

int main() {
    Product p { .name_ = "box", .inStock_ {true }};
    Print(p);
  
    Date d { .t { .hour = 10, .minute = 35 }, .year = 2050, .month = 5, .day = 10 };

    // pass to a function:
    Print({.name_ = "tv", .inStock_ {true }, .price_{100.0}});

    // not all members used:
    Print({.name_ = "car", .price_{2000.0}});
}

