#include <iostream>

template <typename Derived>
class InstanceCounter {
    static inline size_t counter_ { 0 };

public:
    InstanceCounter() noexcept { ++counter_; }
    InstanceCounter(const InstanceCounter& ) noexcept { ++counter_; }
    InstanceCounter(InstanceCounter&& ) noexcept { ++counter_; }
    ~InstanceCounter() noexcept { --counter_;}    

    static size_t GetInstanceCounter() { return counter_; }    
};

struct Value : InstanceCounter<Value> {
	int val { 0 };  
};
struct Wrapper : InstanceCounter<Wrapper> {
	double val { 0.0 };
};

int main() {
    Value v;
    Wrapper w;
    std::cout << "Values: " << Value::GetInstanceCounter() << '\n';
    std::cout << "Wrappers: " << Wrapper::GetInstanceCounter() << '\n';
}