// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2023
// MIT License

// run at https://godbolt.org/z/evMxo19Wj

#include <gtest/gtest.h>

struct Point {
    double x;
    double y;
};

TEST(PointTest, X) {    
    Point p;
    EXPECT_DOUBLE_EQ(1.0, p.x);
}

TEST(PointTest, Y) {    
    Point p;
    EXPECT_DOUBLE_EQ(2.0, p.y);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}