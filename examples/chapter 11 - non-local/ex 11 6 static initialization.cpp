#include <iostream>

struct Value {
    Value(int x) : v(x) { std::cout << "Value(" << v << ")\n"; }
    ~Value() noexcept { std::cout << "~Value(" << v << ")\n"; }

    int v {0};
};

double z = 100.0;
int x;
Value v{42};

int main() {
    puts("main starts...");
    std::cout << x << '\n';
    puts("main ends...");
}