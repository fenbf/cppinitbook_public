// ex 13 3 instance counter.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>

class InstanceCounter {
    static inline size_t counter_ { 0 };

public:
    InstanceCounter() noexcept { ++counter_; }
    InstanceCounter(const InstanceCounter& ) noexcept { ++counter_; }
    InstanceCounter(InstanceCounter&& ) noexcept { ++counter_; }
    ~InstanceCounter() noexcept { --counter_;}    

    static size_t GetInstanceCounter() { return counter_; }    
};

struct Value : InstanceCounter {
	int val { 0 };  
};
struct Wrapper : InstanceCounter {
	double val { 0.0 };
};

int main() {
    Value v;
    Wrapper w;
    std::cout << "Values: " << Value::GetInstanceCounter() << '\n';
    std::cout << "Wrappers: " << Wrapper::GetInstanceCounter() << '\n';
}

