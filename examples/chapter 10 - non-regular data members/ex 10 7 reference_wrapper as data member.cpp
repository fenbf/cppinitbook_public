// ex 10 7 reference_wrapper as data member.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class WrapperWitStdhRef {
public:    
    WrapperWitStdhRef() = default; // cannot make it default...
    explicit WrapperWitStdhRef(std::string& n)
    : name_(n)
    { }

    const std::string& name() const { return name_; }
    void rebind(std::string& name) { name_ = name; }
    void name(const std::string& name) { name_.get() = name; }

private:
    std::reference_wrapper<std::string> name_;
};

int main() {
    std::string str { "Name"};
    WrapperWitStdhRef w { str };
    w.name(str);
    WrapperWitStdhRef x { w };
    std::cout << "str:      " << str << '\n';
    std::cout << "x.name(): " << x.name() << '\n';
    x.name("abc");
    std::cout << "str:      " << str << '\n';
    std::cout << "x.name(): " << x.name() << '\n';

    //WrapperWitStdhRef def {}; // cannot default construct                             
    x = w; // fine now
}

