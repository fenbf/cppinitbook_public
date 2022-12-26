#include <iostream>
#include <vector>

struct Value {
    Value(int x) : v(x) { std::cout << "Value(" << v << ")\n"; }
    Value(const Value& rhs) : v{rhs.v}  {std::cout << "copy Value(" << v << ")\n"; }
    Value(Value&& rhs) : v{rhs.v}  {std::cout << "move Value(" << v << ")\n"; }
    ~Value() noexcept { std::cout << "~Value(" << v << ")\n"; }

    int v {0};
};

int main() {
    std::vector<Value> vals {
        1, 2,
    };

    std::vector<Value> moreVals;
    moreVals.reserve(4);
    std::cout << "with emplace... \n";
    moreVals.emplace_back(3);
    moreVals.emplace_back(4);
    std::cout << "with push... \n";
    moreVals.push_back(5);
    moreVals.push_back(6);
}