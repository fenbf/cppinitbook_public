// ex 5 6 a memory leak.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <exception>
#include <iostream>
#include <string>
#include <memory>

constexpr int MIN_ID = 100;

struct Resource {
    Resource() = default;
    ~Resource() { std::cout << "~Resource\n"; }
};

class Product {
public:    
    explicit Product(int id)
    : res_(new Resource())
    { 
        std::cout << "Product: id " << id << '\n';
        if (id < MIN_ID)
            throw std::runtime_error{"bad id..."};
    }

    ~Product() {
        delete res_;
        std::cout <<  "~Product...\n";
    }

private:
    Resource* res_;
};

int main() {
    try {
        Product invalid(MIN_ID - 1);
    }
    catch (const std::exception& ex) {
        std::cout << "exception: " << ex.what() << '\n';
    }
}

