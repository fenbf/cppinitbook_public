// ex 11 5 beging and end of a thread_local.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <thread>
#include <mutex>

struct Value {
    Value(int x) : v(x) { std::cout << "Value(" << v << ")\n"; }
    ~Value() noexcept { std::cout << "~Value(" << v << ")\n"; }

    int v {0};
};

thread_local Value x { 42 };

void foo() {
    std::cout << "foo()\n";
    x.v = 100;
}

int main() {
    std::cout << "main " << std::this_thread::get_id() << '\n';
    {
        std::jthread worker1 { foo };
        std::jthread worker2 { foo };
    }
    std::cout << "end main()\n";
}

