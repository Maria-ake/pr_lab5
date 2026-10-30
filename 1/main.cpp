#include <iostream>
#include "longarithmetic.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\nЛабораторная работа №2.\n";
        cout << "1. Вычислить input_1! (input_1 > 100)\n";
        cout << "2. Вычислить 2^input_1 (input_1 > 64)\n";
        cout << "3. Вычислить 2^input_1 + 2^input_2 (input_1, input_2 > 64)\n";
        cout << "4. Вычислить 2^input_1 - 2^input_2 (input_1 > input_2 > 64)\n";
        cout << "5. Вычислить input_1-й элемент Фибоначчи (input_1 > 100)\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n = readInt("Введите input_1 (>100): ", 100);
            cout << n << "! = ";
            printNumber(factorial(n));
            break;
        }
        case 2: {
            int n = readInt("Введите input_1 (>64): ", 64);
            cout << "2^" << n << " = ";
            printNumber(powerOfTwo(n));
            break;
        }
        case 3: {
            int a = readInt("Введите input_1 (>64): ", 64);
            int b = readInt("Введите input_2 (>64): ", 64);

            cout << "2^" << a << " + 2^" << b << " = ";
            printNumber(add(powerOfTwo(a), powerOfTwo(b)));
            break;
        }
        case 4: {
            int a, b;

            do {
                a = readInt("Введите input_1 (>64): ", 64);
                b = readInt("Введите input_2 (>64): ", 64);

                if (a <= b) {
                    cout << "Ошибка: нужно input_1 > input_2.\n";
                }
            } while (a <= b);

            cout << "2^" << a << " - 2^" << b << " = ";
            printNumber(sub(powerOfTwo(a), powerOfTwo(b)));
            break;
        }
        case 5: {
            int n = readInt("Введите input_1 (>100): ", 100);

            cout << n << "-й элемент Фибоначчи = ";
            printNumber(fibonacci(n));
            break;
        }
        case 0:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный пункт меню.\n";
        }

    } while (choice != 0);

    return 0;
}