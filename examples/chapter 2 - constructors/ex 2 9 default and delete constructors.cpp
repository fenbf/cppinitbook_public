// ex 2 9 default and delete constructors.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

struct Value {
    Value() = default;

    int x;
};

struct CtorValue {
    CtorValue() = default;
    CtorValue(int v): x{v} { }
    int x;
};

struct DeletedValue {
    DeletedValue() = delete;
    DeletedValue(int v): x{v} { }
    int x;
};

int main() {
    Value v;         // fine, default constructor available    
    CtorValue y;     // ok now, default ctor available
    CtorValue z{10}; // using custom ctor    
    // DeletedValue w;   // err, deleted ctor!
    DeletedValue u{10}; // using custom ctor
}

