// ex 5 5 partial object creation.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <exception>
#include <iostream>
#include <string>

class Product {
public:    
    explicit Product(const char* name, unsigned id)
    : name_(name)
    , id_(id)
    { 
        std::cout << name << ", id " << id << '\n';
        if (id < 100)
            throw std::runtime_error{"bad id..."};
    }

    ~Product() {
        std::cout << name_ << " destructor...\n";
    }

    std::string Name() const { return name_; }
    unsigned Id() const { return id_; }

private:
    std::string name_; 
    unsigned id_; 
};

int main() {
    try {
        Product tvset("TV Set", 123);
        Product car("Mustang", 9);
    }
    catch (const std::exception& ex) {
        std::cout << "exception: " << ex.what() << '\n';
    }
}

