#ifndef DIVIDER_H
#define DIVIDER_H

// Частное от деления dividend / divisor с округлением к нулю.
// Бросает std::invalid_argument при divisor == 0.
// При переполнении signed int возвращает ближайшее значение (INT_MAX).
int safeDivide(int dividend, int divisor);

#endif // DIVIDER_H