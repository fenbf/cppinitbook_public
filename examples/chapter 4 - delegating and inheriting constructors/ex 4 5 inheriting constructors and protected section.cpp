struct Base {
    int x{};
    int y{};
    
    Base(int a, int b): x{a}, y{b} { }
protected:
    Base() = default;
    Base(int a): x{a} { }
};

struct Derived : public Base {
    using Base::Base;

    //Derived(int a) : Base{a} { }
};

int main() {
    // Derived d{0};  // error: 'Base::Base(int)' is protected
    Derived d2{0, 1}; // fine
}