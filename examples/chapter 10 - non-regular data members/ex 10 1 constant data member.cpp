// ex 10 1 constant data member.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:    
    explicit Product(const char* name, unsigned id)
    : name_(name)
    , id_(id)
    { }

    const std::string& name() const { return name_; }
    void name(const std::string& name) { name_ = name; }
    unsigned id() const { return id_; }

private:
    std::string name_; 
    const unsigned id_; 
};

int main() {
   Product tvset("TV Set", 123);
   std::cout << tvset.name() << ", id: " 
             << tvset.id() << '\n';
}

