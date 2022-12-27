// ex 2 7 adding constructors to packet.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <numeric>

size_t calcCheckSum(const std::string& s) {
    return std::accumulate(s.begin(), s.end(), 0ul);
}

class DataPacket {
    std::string data_;
    size_t checkSum_;
    size_t serverId_;

public:
    DataPacket()
    : data_{}
    , checkSum_{0}
    , serverId_{0}
    { }
    
    DataPacket(const std::string& data, size_t serverId)
    : data_{data}
    , checkSum_{calcCheckSum(data)}
    , serverId_{serverId}
    { }

    const std::string& getData() const { return data_; }
    void setData(const std::string& data) {
        data_ = data;
        checkSum_ = calcCheckSum(data);
    }
    size_t getCheckSum() const { return checkSum_; }
    
    void setServerId(size_t id) { serverId_ = id; }
    size_t getServerId() const { return serverId_; }
};

void printInfo(const DataPacket& packet) {
    std::cout << "data: " << packet.getData() << '\n';
    std::cout << "checkSum: " << packet.getCheckSum() << '\n';
    std::cout << "serverId: " << packet.getServerId() << '\n';
}

int main() {
    DataPacket empty;
    printInfo(empty);
    DataPacket zeroed{};
    printInfo(zeroed);
    DataPacket packet{"Hello World", 101};
    printInfo(packet);
    DataPacket reply{"Hi, how are you?", 404};
    printInfo(reply);
}

