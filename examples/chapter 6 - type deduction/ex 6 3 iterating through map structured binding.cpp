#include <map>
#include <iostream>

int main() {
    const std::map<std::string, int> mapCityPopulation {
        { "Beijing", 21'707'000 },
        { "London", 8'787'892 },
        { "New York", 8'622'698 }
    };
    
    for (auto&[city, population] : mapCityPopulation)
        std::cout << city << ": " << population << '\n';
}