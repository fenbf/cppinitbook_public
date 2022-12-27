// ex 5 8 compiler generated destructor.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:
    explicit Product(int id, const std::string& name) 
        : id_(id), name_(name)
    {
        std::cout << "Product(): " << id_ << ", " << name_ << '\n';
    }

private:
    int id_;
    std::string name_;
};

int main() {
    Product first{10, "basic"};
}

