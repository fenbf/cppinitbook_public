// ex 11 4 thread_local.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutPrint;
thread_local int x = 0;

void foo() {
    thread_local int y = 0;
    std::lock_guard guard(mutPrint);
    std::cout << "in thread\t" << std::this_thread::get_id() << " ";
    std::cout << "&x " << &x << ", ";
    std::cout << "&y " << &y << '\n';
}

int main() {
    std::cout << "main    \t" << std::this_thread::get_id() << " &x " << &x << '\n';

    std::jthread worker1 { foo };
    foo();
    std::jthread worker2 { foo };
    foo();
}

