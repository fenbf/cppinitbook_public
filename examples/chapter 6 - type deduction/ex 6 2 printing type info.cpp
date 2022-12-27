// ex 6 2 printing type info.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>

template <typename T>
constexpr auto type_name() -> std::string_view {
    constexpr auto prefix = std::string_view{"with T = "};
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
    const auto start = function.find(prefix) + prefix.size();
    return function.substr(start, function.find("; ") - start);
}

template <typename T, typename... Ts>
void typeNames(const char*str ) {
    std::cout << str << type_name<T>();
    ((std::cout << ", " << type_name<Ts>()), ...);
}

int main() {
    int num = 42;
    int& rnum = num;
    const int& crnum = num;
        
    auto c { num }; 
    auto c2 { rnum }; 
    auto c3 { crnum };
    typeNames<decltype(c), decltype(c2), decltype(c3)>("c, c2, c3: ");

    auto x { 42 };      // x is int
    auto y = 42;        // y is int
    auto z = { 42 };    // z is initializer_list<int>!
    typeNames<decltype(x), decltype(y), decltype(z)>("\nx, y, z: ");

    struct Object { std::string str; };
    const Object unknown { "unknown" };    
    const Object& refunknown = unknown;
    auto&& u = unknown;
    auto&& refu = refunknown;
    typeNames<decltype(u), decltype(refu)>("\nu and refu: ");
}


