// ex 10 3 unique_ptr as data member.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>
#include <memory>

struct Value {
    explicit Value(int v) : v_(v) { std::cout << "Value(" << v_ << ")\n"; }
    ~Value() noexcept { std::cout << "~Value(" << v_ << ")\n"; }

    int v_;
};

class ProductUniquePointer {
public:    
    ProductUniquePointer() = default;
    explicit ProductUniquePointer(const char* name, 
                                  std::unique_ptr<Value> pId)
    : name_(name)
    , pId_(std::move(pId))
    { }

    const std::string& name() const { return name_; }
    int id() const { return pId_ ? pId_->v_ : 0; }

private:
    std::string name_; 
    std::unique_ptr<Value> pId_;
};

int main() {
    auto pId = std::make_unique<Value>(123);
    ProductUniquePointer tvset{"TV Set", std::move(pId)};
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';
    ProductUniquePointer copy { std::move(tvset) };
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';
    std::cout << "copy:  " << copy.name() << ", id: " << copy.id() << '\n';
    //ProductConst empty;
    //copy = tvset; // error
}

