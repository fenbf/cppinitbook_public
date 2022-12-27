// ex 13 5 multiple initializations.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <array>
#include <iostream>
#include <random>
#include <string>

struct Flags {
    unsigned bppMode_ : 4 { 0 }; // bits per pixel
    unsigned visible_ : 2 { 1 };
    unsigned extData  : 2 { 0 };
};

template <typename Derived>
class InstanceCounter {
    static inline size_t counter_ { 0 };

public:
    InstanceCounter() noexcept { ++counter_; }
    InstanceCounter(const InstanceCounter& ) noexcept { ++counter_; }
    InstanceCounter(InstanceCounter&& ) noexcept { ++counter_; }
    ~InstanceCounter() noexcept { --counter_;}    

    static size_t GetInstanceCounter() { return counter_; }    
};

class Window : public InstanceCounter<Window> {        
    static constexpr unsigned default_width { 1028 };
    static constexpr unsigned default_height { 768 };
    static constexpr unsigned default_bpp { 8 };
    
    unsigned width_ { default_width };
    unsigned height_ { default_height };
    Flags flags_ {.bppMode_ { default_bpp } };
    std::string title_ { "Default Window" };
    
public:
    Window() = default;
    explicit Window(std::string title) : title_(std::move(title)) { }
    Window(std::string title, unsigned w, unsigned h) :
    width_(w), height_(h), title_(std::move(title)) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Window& w) {
        os << w.title_ << ": " << w.width_ << "x" << w.height_; 
        return os;
    }
};

void WindowDemo() {
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 20);

    const int windowCount = std::uniform_int_distribution<>(2, 10)(gen);
    std::cout << "Generating " << windowCount << " random Windows\n";

    const std::array adjs { "regular ", "empty ", "blue ", "super " };
    const std::array nouns { "app", "tool", "console", "game" };
    const std::array sizes { 1080u, 1920u, 768u, 320u, 640u, 3840u, 800u };

    std::vector<Window> windows;
    for (int i = 0; i < windowCount; ++i) {
        const auto r = distrib(gen);
        const auto r2 = distrib(gen);
        const auto name = std::string { adjs[(r + i) % adjs.size()] } + nouns[r2 % nouns.size()];
        Window w{name, sizes[r2 % sizes.size()], sizes[r % sizes.size()]};
        windows.push_back(w);
        // or emplace:
        //windows.emplace_back(name, sizes[r2 % sizes.size()], sizes[r % sizes.size()]);
    }

    for (const auto& w : windows)
        std::cout << w << '\n';

    std::cout << "Created " << Window::GetInstanceCounter() << " Windows\n";
}

int main() {
    WindowDemo();

    if (Window::GetInstanceCounter() != 0)
        std::cout << Window::GetInstanceCounter() << " Windows are still alive!\n";
}

