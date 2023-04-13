// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2023
// MIT License

// run at https://godbolt.org/z/7YYKMj8eW

#include <gtest/gtest.h>
#include <vector>

struct SalesRec {    
    std::string name_;
    double price_;
};

void addPromo(std::vector<SalesRec>& sales, double discount) {
    for (auto elem : sales)        
        elem.price_ = (1.0-discount)*elem.price_;
}

double computeTotal(const std::vector<SalesRec>& sales) {
    double sum;
    for (auto elem : sales)
        sum += elem.price_;
    return sum;
}

TEST(computeTotal, empty) {    
    SalesRec s;
    EXPECT_DOUBLE_EQ(0, computeTotal({s}));
}

TEST(computeTotal, several) {    
    SalesRec s, s1;
    SalesRec s2 { "thing", 1.0 };
    EXPECT_DOUBLE_EQ(1.0, computeTotal({s, s1, s2}));
}

TEST(addPromo, simple) {    
    std::vector<SalesRec> vec{{"thing", 1.0}};
    addPromo(vec, 0.1);
    EXPECT_DOUBLE_EQ(0.9, vec[0].price_);
}

TEST(addPromo, two) {    
    std::vector<SalesRec> vec{{"thing", 1.0}, {"toy", 10.0}};
    addPromo(vec, 0.5);
    EXPECT_DOUBLE_EQ(0.5, vec[0].price_);
    EXPECT_DOUBLE_EQ(5.0, vec[1].price_);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}