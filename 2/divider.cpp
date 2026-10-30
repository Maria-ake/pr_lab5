#include "divider.h"

#include <cstdint>
#include <limits>
#include <stdexcept>

namespace {

// Вычитание без оператора '-' : a - b = a + (~b) + 1
std::uint32_t usub(std::uint32_t a, std::uint32_t b) {
    return a + (~b) + 1u;
}

// Модуль числа как uint32 (в дополнительном коде)
std::uint32_t toAbs(int x) {
    std::uint32_t u = static_cast<std::uint32_t>(x);
    if (x < 0) u = ~u + 1u;
    return u;
}

} // namespace

int safeDivide(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero");
    }

    // Единственный случай переполнения: INT_MIN / -1 = 2^31
    if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
        return std::numeric_limits<int>::max();
    }

    const bool negative = (dividend < 0) != (divisor < 0);

    std::uint32_t ua = toAbs(dividend);
    std::uint32_t ub = toAbs(divisor);

    // Двоичное длинное деление: только +, ~, &, |, <<, >>
    std::uint32_t quotient  = 0;
    std::uint32_t remainder = 0;

    for (std::uint32_t bit = 0x80000000u; bit != 0u; bit >>= 1) {
        remainder = (remainder << 1) | ((ua & bit) ? 1u : 0u);
        if (remainder >= ub) {                  // сравнение, не вычитание
            remainder = usub(remainder, ub);    // только + и ~
            quotient |= bit;
        }
    }

    if (negative) {
        quotient = ~quotient + 1u;              // смена знака через доп. код
    }

    return static_cast<int>(quotient);
}