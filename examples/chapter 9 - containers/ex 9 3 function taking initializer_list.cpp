// ex 9 3 function taking initializer_list.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <initializer_list>

void foo(std::initializer_list<int> list) {
    if (!std::empty(list))
    {    
        for (auto& x : list)
            std::cout << x << ", ";
        std::cout << "(" << list.size() << " elements)\n";        
    }
    else
        std::cout << "empty list\n";
}

int main() {
    foo({});
    foo({1, 2, 3});
    foo({1, 2, 3, 4, 5});
}

