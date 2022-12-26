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