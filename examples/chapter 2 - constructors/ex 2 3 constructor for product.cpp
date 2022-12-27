// ex 2 3 constructor for product.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:
    Product() : id_{-1}, name_{"none"} { } // a default constructor
    Product(int id, const std::string& name) 
        : id_{id}, name_{name} { }

    int Id() const { return id_; }
    std::string Name() const { return name_; }

private:
    int id_;
    std::string name_;
};

int main() {
    Product none;
    std::cout << none.Id() << ", " << none.Name() << '\n';

    Product car(10, "super car");
    std::cout << car.Id() << ", " << car.Name() << '\n';

    Product tvSet{77, "tv set" }; 
    std::cout << tvSet.Id() << ", " << tvSet.Name() << '\n';
}

