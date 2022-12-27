// ex 4 1 delegating constructors.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product {
public:
    Product(int id, unsigned quantity, const std::string& name) 
        : id_{id}, quantity_{quantity}, name_{name}
    {  
        verifyData();
    }

    Product(const std::string& name, int id = 0) 
        : Product{id, 0, name}
    { }

    void verifyData() {
        if (quantity_ > MaxQuantity)
            throw std::invalid_argument("qantity is too large!");
    }

    std::string getName() const { return name_; }

private:
    int id_;
    unsigned quantity_;
    std::string name_;

    static constexpr unsigned MaxQuantity = 100;
};

int main() {
    try {
        Product box{"a box"};
        std::cout << "product: " << box.getName() << " created... \n";

        Product toy{101, 200, "a box"};
        std::cout << "product: " << toy.getName() << " created... \n";
    }
    catch (const std::exception& e) {
        std::cout << "cannot create: " << e.what() << '\n';
    }
}

