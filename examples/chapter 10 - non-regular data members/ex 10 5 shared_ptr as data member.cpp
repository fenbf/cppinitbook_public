// ex 10 5 shared_ptr as data member.cpp
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

class ProductWithSharedPtr {
public:    
    ProductWithSharedPtr() = default;
    explicit ProductWithSharedPtr(const char* name, 
                                  std::shared_ptr<Value> pId)
    : name_(name)
    , pId_(pId)
    { }

    const std::string& name() const { return name_; }
    int id() const { return pId_ ? pId_->v_ : 0; }

private:
    std::string name_; 
    std::shared_ptr<Value> pId_;
};

int main() {
    auto pId = std::make_shared<Value>(123);
    ProductWithSharedPtr tvset{"TV Set", pId};
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';
    std::cout << "pId use count: " << pId.use_count() << '\n';
    {
        ProductWithSharedPtr copy { tvset };
        std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';
        std::cout << "copy:  " << copy.name() << ", id: " << copy.id() << '\n';
        pId->v_ = 100;
        std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';
        std::cout << "copy:  " << copy.name() << ", id: " << copy.id() << '\n';
        std::cout << "pId use count: " << pId.use_count() << '\n';
    }
    std::cout << "pId use count: " << pId.use_count() << '\n';
}

