// ex 12 2 initialization with round parens.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

struct Point { int x; int y; };
struct PointExt { Point pt; int z; };

int main() {
    // C++20 and parens:
    Point pt (1, 2);
    // Point pt = (1, 2); // doesn't work, wrong syntax
    Point pt1 = {1, 2}; // fine with braces
    
    //Point pt2 { 1.1, 2.2 }; // narrowing prevented
    Point pt3 ( 1.1, 2.2 );   // narrowing is fine

    PointExt pt4 { 4, 5, 6};     // brace elision works
    //PointExt pt5 ( (4, 5), 6); // nesting doesn't work
    // PointExt pt5 ( 4, 5, 6);  // brace elision doesn't work
    PointExt pt5 ( Point(4, 5), 6); // need to be explicit

    double params[] (9.81, 3.14, 1.44);
    // double paramsDeduced[] = (9.81, 3.14, 1.44); // wrong syntax
    int arrX[10]  (1, 2, 3, 4); // rest is 0
}

