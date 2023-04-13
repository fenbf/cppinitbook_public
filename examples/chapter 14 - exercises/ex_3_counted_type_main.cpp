// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2023
// MIT License

// run at https://wandbox.org/permlink/GuGzTWKF8irN2YLz

#include <iostream>
#include "countedType.h"

struct Tests {    
    static void Expect(int ex, int val) {
        if (ex != val) {
            std::cout << ex << " != " << val << '\n';
            ++failedTests;
        }
        ++allTests;
    }
    static void Summary() {
        if (failedTests > 0)
            std::cout << failedTests << " Failed Tests! Out of " << allTests << '\n';
        else
            std::cout << "All (" << allTests << ") tests passed!\n";
    }
private:
    static inline int failedTests = 0;
    static inline int allTests = 0;
};

int main() {
    {
        CountedType c0;
        CountedType c1;
        Tests::Expect(2, CountedType::instanceCounter);
        Tests::Expect(2, CountedType::maxInstanceCounter);
        
        CountedType c2(c1);
        CountedType c3(c1);
        Tests::Expect(4, CountedType::instanceCounter);
        Tests::Expect(4, CountedType::maxInstanceCounter);

        CountedType c4(std::move(c1));
        Tests::Expect(5, CountedType::instanceCounter);
        Tests::Expect(5, CountedType::maxInstanceCounter);
    }
    Tests::Expect(0, CountedType::instanceCounter);
    Tests::Expect(5, CountedType::maxInstanceCounter);

    Tests::Summary();
}