// ex 3 10 logging in data packet.cpp
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
    { 
        std::cout << "Ctor for \"" << data_ << "\"\n";
    }

    DataPacket(const DataPacket& other) 
    : data_{other.data_}
    , checkSum_{other.checkSum_}
    , serverId_{other.serverId_}
    {
        std::cout << "Copy ctor for \"" << data_ << "\"\n";
    }

    DataPacket(DataPacket&& other) 
    : data_{std::move(other.data_)}   // move string member...
    , checkSum_{other.checkSum_}       // no need to move built-in types...
    , serverId_{other.serverId_}  
    {
        other.checkSum_ = 0; // leave this in a proper state
        std::cout << "Move ctor for \"" << data_ << "\"\n";
    }

    DataPacket& operator=(const DataPacket& other) {
        if (this != &other) {
            data_ = other.data_;
            checkSum_ = other.checkSum_;
            serverId_ = other.serverId_;
            std::cout << "Assignment for \"" << data_ << "\"\n";
        }
        return *this;
    }

    DataPacket& operator=(DataPacket&& other) {
        if (this != &other) {
            data_ = std::move(other.data_);
            checkSum_ = other.checkSum_;
            other.checkSum_ = 0; // leave this in a proper state
            serverId_ = other.serverId_;
            std::cout << "Move Assignment for \"" << data_ << "\"\n";
        }
        return *this;
    }

    const std::string& getData() const { return data_; }
    void setData(const std::string& data) {
        data_ = data;
        checkSum_ = calcCheckSum(data);
    }
    size_t getCheckSum() const { return checkSum_; }
    
    void setServerId(size_t id) { serverId_ = id; }
    size_t getServerId() const { return serverId_; }
};

int main() {
    DataPacket firstMsg {"first msg", 101 };
    DataPacket copyMsg { firstMsg };

    DataPacket secondMsg { "second msg", 202 };
    copyMsg = secondMsg;
    
    DataPacket movedMsg { std::move(secondMsg)};
    // now we stole the data, so it should be empty...
    std::cout << "secondMsg's data after move ctor): \"" 
              << secondMsg.getData() << "\", sum: " 
              << secondMsg.getCheckSum() << '\n';

    movedMsg = std::move(firstMsg);

    // now we stole the name, so it should be empty...
    std::cout << "firstMsg's data after move ctor): \"" 
              << firstMsg.getData() << "\", sum: " 
              << firstMsg.getCheckSum() << '\n';
}

