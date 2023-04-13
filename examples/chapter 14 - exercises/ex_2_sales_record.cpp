// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2023
// MIT License

// run at https://godbolt.org/z/revGqKMvo

#include <gtest/gtest.h>

constexpr unsigned int DEFAULT_CATEGORY = 4;
constexpr unsigned int DEFAULT_FLAGS = 0x0a;

struct SalesRecord {
    std::string name_;
    double price_;
    unsigned int category_ : 4;
    unsigned int flags_ : 4;
};

TEST(SalesRecord, Name) {    
    SalesRecord s;
    EXPECT_EQ("empty", s.name_);
}

TEST(SalesRecord, Price) {    
    SalesRecord s;
    EXPECT_DOUBLE_EQ(1.0, s.price_);
}

TEST(SalesRecord, Category) {    
    SalesRecord s;
    EXPECT_EQ(DEFAULT_CATEGORY, s.category_);
}

TEST(SalesRecord, Flags) {    
    SalesRecord s;
    EXPECT_EQ(DEFAULT_FLAGS, s.flags_);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}