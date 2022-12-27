// ex 9 6 package class with initializer_list.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Product {
    Product() = default;
    Product(std::string s, double v) 
    : name{std::move(s)}, value{v} 
    { }
    
    std::string name;
    double value{};
};

class Package {
public:
    Package() = default;
    Package(std::initializer_list<Product> items) {
        for (auto& elem : items)
            addProduct(elem);
    }

    void addProduct(const Product& p) {
        ++counts_[p.name];
        prods_.push_back(p);
        totalValue_ += p.value;
    }
    void printContents() const {
        for (auto& [key, val] : counts_)
            std::cout << key << ", count: " << val<< '\n';
        std::cout << "total value: " << totalValue_ << '\n';
    }
private:
    std::vector<Product> prods_; // all products
    std::map<std::string, unsigned> counts_;
    double totalValue_ { };
};

int main() {
    Package pack;
    pack.addProduct({"crayons", 3.0});
    pack.addProduct({"pen", 2.0});
    pack.addProduct({"bricks", 11.0});
    pack.addProduct({"bricks", 12.0});
    pack.addProduct({"pen", 12.0});
    pack.addProduct({"pencil", 12.0});
    pack.printContents();
}

