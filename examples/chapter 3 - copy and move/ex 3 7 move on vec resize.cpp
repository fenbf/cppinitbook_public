// ex 3 7 move on vec resize.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>
#include <vector>

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

    Product(Product&& other) noexcept
        : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::cout << "Product(move): " << id_ << ", " << name_ << '\n';
    }

    std::string Name() const { return name_; }

private:
    int id_;
    std::string name_;
};

int main() {
    std::vector<Product> prods;
    prods.emplace_back(101, "car");
    prods.emplace_back(202, "box");
    prods.emplace_back(303, "toy");
    prods.emplace_back(404, "mug");
    prods.emplace_back(505, "pencil");
}

