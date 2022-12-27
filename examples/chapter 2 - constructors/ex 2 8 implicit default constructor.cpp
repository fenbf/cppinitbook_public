// ex 2 8 implicit default constructor.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

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

