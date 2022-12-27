// ex 9 8 trying to pass unique_ptr.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <vector>
#include <memory>

struct Shape {
    virtual void render() const {
        std::cout << "rendering shape\n";
    }
};

struct Circle : Shape {
    void render() const override {
        std::cout << "rendering circle\n";
    }
};

struct Rectangle : Shape {
    void render() const override {
        std::cout << "rendering rectangle\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes {
        std::make_unique<Circle>(), std::make_unique<Rectangle>()
    };
}

