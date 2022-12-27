// ex 4 4 inheriting constructors.cpp
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

class DebugDataPacket : public DataPacket {
public:
    using DataPacket::DataPacket;

    void DebugPrint(std::ostream& os) {
        os << getData() << ", " << getCheckSum() << '\n';
    }
};

int main() {
    DebugDataPacket hello{"hello!", 404};
    hello.DebugPrint(std::cout);
}

