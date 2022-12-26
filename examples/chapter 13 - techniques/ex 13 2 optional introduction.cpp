#include <iostream>
#include <optional>

int main() {
    std::optional<double> empty;
    std::optional<std::string> ostr{"Hello World"};
    std::optional<int> oi{10};

    // has_value()
    if (empty.has_value()) std::cout << *empty << '\n';
    else std::cout << "empty is empty\n";

    // operator bool
    if (ostr) std::cout << *ostr << '\n';
    else std::cout << "ostr is empty\n";

    // value_or()
    std::cout << oi.value_or(42) << '\n';
}