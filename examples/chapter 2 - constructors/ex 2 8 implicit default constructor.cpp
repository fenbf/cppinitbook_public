struct Value {
    int x;
};

struct CtorValue {
    CtorValue(int v): x{v} { }
    int x;
};

int main() {
    Value v;         // fine, default constructor available
    // CtorValue y;     // error! no default ctor available
    CtorValue z{10}; // using custom ctor
}