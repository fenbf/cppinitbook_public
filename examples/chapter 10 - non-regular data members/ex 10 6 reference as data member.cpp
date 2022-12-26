#include <iostream>
#include <string>

class WrapperWithRef {
public:    
    WrapperWithRef() = default; // cannot make it default...
    explicit WrapperWithRef(std::string& n)
    : name_(n)
    { }

    const std::string& name() const { return name_; }
    void name(const std::string& name) { name_ = name; }

private:
    std::string& name_; // cannot set to "nullptr" or {} empty!
};

int main() {
    std::string str { "Name"};
    WrapperWithRef w { str };
    w.name(str);
    WrapperWithRef x { w };
    std::cout << "str:      " << str << '\n';
    std::cout << "x.name(): " << x.name() << '\n';
    x.name("abc");
    std::cout << "str:      " << str << '\n';

    //WrapperWithRef def {}; // cannot default construct                             
    //x = w; // error, cannot assign
}