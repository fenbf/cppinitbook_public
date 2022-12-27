// ex 9 5 package class demo.cpp
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
    Product() : name{}, value {} { }
    Product(const std::string& s, double v) 
        : name{s}
        , value{v} 
    { }
    
    std::string name;
    double value;
};

class Package {
public:
    Package() : totalValue_ { 0.0 } { }

    void AddProduct(const Product& p) {
        ++counts_[p.name];
        prods_.push_back(p);
        totalValue_ += p.value;
    }
    void PrintContents() const {
        for (auto& [key, val] : counts_)
            std::cout << key << ", count: " << val<< '\n';
        std::cout << "total value: " << totalValue_ << '\n';
    }
private:
    std::vector<Product> prods_; // all products
    std::map<std::string, unsigned> counts_;
    double totalValue_;
};

int main() {
    Package pack;
    pack.AddProduct({"crayons", 3.0});
    pack.AddProduct({"pen", 2.0});
    pack.AddProduct({"bricks", 11.0});
    pack.AddProduct({"bricks", 12.0});
    pack.AddProduct({"pen", 12.0});
    pack.AddProduct({"pencil", 12.0});
    pack.PrintContents();
}

