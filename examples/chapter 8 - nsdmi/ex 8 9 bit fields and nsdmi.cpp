#include <iostream>

struct Type {
    int value : 4 = 1;
    int second : 4 { 2 };
};

int main() {
    Type t;
    std::cout << t.value << '\n';
    std::cout << t.second << '\n';
}