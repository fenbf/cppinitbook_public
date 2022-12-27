// ex 4 3 base class constructor order.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:
    Product() : id_{0} { std::cout << "Product() default\n"; }
    explicit Product(int id, const std::string& name) 
        : id_{id}, name_{name}
    {
        std::cout << "Product(): " << id_ << ", " << name_ << '\n';
    }

protected:
    int id_;
    std::string name_;
};

class ExProduct : public Product {
public:
    ExProduct() { std::cout << "ExProduct() default\n"; }
    explicit ExProduct(int id) { 
        id_ = id; 
        std::cout << "ExProduct(id)\n";
    }
};

int main() {
    ExProduct p;
    ExProduct withId{42};
}

