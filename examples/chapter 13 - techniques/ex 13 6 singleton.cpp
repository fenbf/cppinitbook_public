// ex 13 6 singleton.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <cstdio>
class Singleton {
private:
  Singleton() { puts("Singleton()"); }
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }

  void foo() { puts("foo()"); }
  void func() { puts("func()"); }
};

int main() {
    puts("main starts...");
    Singleton::getInstance().foo();
    Singleton::getInstance().func();
}

