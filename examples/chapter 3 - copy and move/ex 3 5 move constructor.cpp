// ex 3 5 move constructor.cpp
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

    Product(Product&& other) noexcept
        : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::cout << "Product(move): " << id_ << ", " << name_ << '\n';
    }

    Product operator+(const std::string s) {
        return Product{id_, name_ + s};
    }

    std::string Name() const { return name_; }

private:
    int id_;
    std::string name_;
};

int main() {
    Product tvSet {100, "tv set"};
    std::cout << tvSet.Name() << " created...\n";
    Product setV2 { std::move(tvSet) };
    std::cout << setV2.Name() << " created...\n";
    std::cout << "old value: " << tvSet.Name() << '\n';
}

