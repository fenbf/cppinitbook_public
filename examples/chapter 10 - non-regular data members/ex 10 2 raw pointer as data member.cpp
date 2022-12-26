#include <iostream>
#include <string>

class DangerousWrapper {
public:    
    explicit DangerousWrapper(std::string* pstr)
    : pName_(pstr)
    { }

    std::string* name() const { return pName_; }
    void name(std::string* pstr) { pName_ = pstr; }

private:
    std::string* pName_ {nullptr};
};

int main() {
    std::string str { "Name"};
    DangerousWrapper w { &str };
    DangerousWrapper x { w };
    std::cout << *w.name() << '\n';
    *(x.name()) = "Other";
    std::cout << *w.name() << '\n';
}