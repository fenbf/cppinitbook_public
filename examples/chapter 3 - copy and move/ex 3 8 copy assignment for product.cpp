// ex 3 8 copy assignment for product.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:
    Product(int id, const std::string& name) 
        : id_{id}, name_{name}
    {
        std::cout << "Product(): " << id_ << ", " << name_ << '\n';
    }

    Product(const Product& other)
        : id_{other.id_}, name_{other.name_}
    {
        std::cout << "Product(copy): " << id_ << ", " << name_ << '\n';
    }

    Product& operator=(const Product& other) {
        if (this == &other)
            return *this;

        id_ = other.id_;
        name_ = other.name_;
        std::cout << "operator=(copy): " << id_ << ", " << name_ << '\n';
        return *this;
    }

    const std::string& name() const { return name_; }

private:
    int id_;
    std::string name_;
};

int main() {
    Product base { 42, "base" };
    Product first { base };  // copy ctor called!
    Product second = first;  // copy ctor called!
    Product third { 100, "third" };
    third = second; // assignment operator called!
}

