#include <iostream>
#include <limits>
#include <exception>

#include "divider.h"

static void test(int a, int b) {
    try {
        std::cout << a << " / " << b << " = " << safeDivide(a, b) << "\n";
    } catch (const std::exception& e) {
        std::cout << a << " / " << b << " -> " << e.what() << "\n";
    }
}

int main() {
    const int IMIN = std::numeric_limits<int>::min();
    const int IMAX = std::numeric_limits<int>::max();

    std::cout << "Задание 2:\n\n";
    std::cout << "Тесты\n";
    test( 7,  2);              //  3
    test(-7,  2);              // -3
    test( 7, -2);              // -3
    test(-7, -2);              //  3
    test( 0,  5);              //  0
    test( 5,  5);              //  1
    test(-5,  5);              // -1
    test( 1,  2);              //  0  (округление к нулю)
    test(-1,  2);              //  0
    test(IMAX,  1);            //  IMAX
    test(IMIN,  1);            //  IMIN
    test(IMIN, -1);            //  IMAX  (переполнение)
    test(IMAX, IMIN);          //  0
    test(IMIN, IMAX);          // -1
    test(10, 0);               //  исключение

    std::cout << "\nИнтерактив (введите 0 0 для выхода ---\n";
    int a, b;
    while (true) {
        std::cout << "> ";
        if (!(std::cin >> a >> b)) break;
        if (a == 0 && b == 0) break;
        test(a, b);
    }
    return 0;
}