#include <iostream>

struct SimpleType {
    int field { 0 };
};

int main() {
    SimpleType st;
    std::cout << "st.field is " << st.field << '\n';
}