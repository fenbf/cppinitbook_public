// ex 5 7 fixing memory leak.cpp
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
    : res_(std::make_unique<Resource>())
    { 
        std::cout << "Product: id " << id << '\n';
        if (id < MIN_ID)
            throw std::runtime_error{"bad id..."};
    }

    ~Product() {
        std::cout <<  "~Product...\n";
    }

private:
    std::unique_ptr<Resource> res_;
};

int main() {
    try {
        Product invalid(MIN_ID - 1);
    }
    catch (const std::exception& ex) {
        std::cout << "exception: " << ex.what() << '\n';
    }
}

