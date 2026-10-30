#include "callchain.h"
#include <iostream>

namespace {
    bool g_throwInt = false;
}

void setThrowInt(bool value) { g_throwInt = value; }


static void f5() {
    std::cout << "[f5] перед try: 1+2 = " << (1 + 2) << "\n";
    if (g_throwInt) {
        std::cout << "[f5] бросаю исключение int\n";
        throw 42;
    } else {
        std::cout << "[f5] бросаю исключение double\n";
        throw 3.14;
    }
    std::cout << "[f5] конец функции (недостижимо)\n";
}

static void f4() {
    std::cout << "[f4] перед вызовом f5\n";
    f5();                               // без try — при исключении код ниже пропускается
    std::cout << "[f4] конец функции (пропущен из-за раскрутки стека)\n";
}

// обрабатывает int
static void f3() {
    std::cout << "[f3] перед try\n";
    try {
        f4();
    } catch (int e) {
        std::cout << "[f3] поймал int: " << e << "\n";
    }
    std::cout << "[f3] конец функции\n";
}

// обрабатывает int и double
static void f2() {
    std::cout << "[f2] перед try\n";
    try {
        f3();
    } catch (int e) {
        std::cout << "[f2] поймал int: " << e << "\n";
    } catch (double e) {
        std::cout << "[f2] поймал double: " << e << "\n";
    }
    std::cout << "[f2] конец функции\n";
}


void f1() {
    std::cout << "[f1] перед вызовом f2\n";
    f2();
    std::cout << "[f1] конец функции\n";
}