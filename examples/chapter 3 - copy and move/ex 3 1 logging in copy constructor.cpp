// ex 3 1 logging in copy constructor.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>
#include <array>

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

    std::string Name() const { return name_; }

private:
    int id_;
    std::string name_;
};

void foo(Product p) {
    std::cout << "inside foo()\n";
}

Product createProduct() {
    return Product{101, "from createProduct()"};
}

int main() {
    Product base { 42, "base product" }; // an initial object
    std::cout << base.Name() << " created\n";
    std::cout << "Product other { base };\n";
    Product other { base };  
    std::cout << "Product another(base);\n";
    Product another(base); 
    std::cout << "Product oneMore = base;\n";
    Product oneMore = base;
    std::cout << "std::array<Product, 2> = { base, other };\n";
    std::array<Product, 2> arr = { base, other };

    std::cout << "calling foo()\n";
    foo(arr[0]);

    std::cout << "calling createProduct()\n";
    Product created = createProduct();
}

