// ex 13 6 singleton.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

class Singleton {
private:
  Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }

  void foo() { }
};

int main() {
    Singleton::getInstance().foo();
}

