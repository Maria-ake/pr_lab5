#ifndef LONGARITHMETIC_H
#define LONGARITHMETIC_H

#include <vector>
#include <string>

// Печать длинного числа. Цифры хранятся в обратном порядке
void printNumber(const std::vector<int>& num);

// Умножение длинного числа на обычное целое b
std::vector<int> multiply(const std::vector<int>& a, int b);

// Сложение двух длинных чисел
std::vector<int> add(const std::vector<int>& a, const std::vector<int>& b);

// Вычитание: a - b
std::vector<int> sub(const std::vector<int>& a, const std::vector<int>& b);

// Факториал: n!
std::vector<int> factorial(int n);

// Возведение 2 в степень n: 2^n
std::vector<int> powerOfTwo(int n);

// n-й элемент последовательности Фибоначчи
std::vector<int> fibonacci(int n);

// Ввод целого числа с проверкой: число должно быть больше minValue
int readInt(const std::string& prompt, int minValue);

#endif // LONGARITHMETIC_H