#include "longarithmetic.h"

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void printNumber(const vector<int>& num) {
    for (auto it = num.rbegin(); it != num.rend(); ++it) {
        cout << *it;
    }
    cout << '\n';
}

vector<int> multiply(const vector<int>& a, int b) {
    if (b == 0) return {0};

    vector<int> res;
    long long carry = 0;

    for (int digit : a) {
        long long prod = 1LL * digit * b + carry;
        res.push_back(static_cast<int>(prod % 10));
        carry = prod / 10;
    }

    while (carry > 0) {
        res.push_back(static_cast<int>(carry % 10));
        carry /= 10;
    }

    return res;
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int carry = 0;
    size_t n = max(a.size(), b.size());

    for (size_t i = 0; i < n || carry; ++i) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];

        res.push_back(sum % 10);
        carry = sum / 10;
    }

    return res;
}

vector<int> sub(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int borrow = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        int diff = a[i] - borrow - (i < b.size() ? b[i] : 0);

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.push_back(diff);
    }

    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    return res;
}

vector<int> factorial(int n) {
    vector<int> res{1};

    for (int i = 2; i <= n; ++i) {
        res = multiply(res, i);
    }

    return res;
}

vector<int> powerOfTwo(int n) {
    vector<int> res{1};

    for (int i = 0; i < n; ++i) {
        res = multiply(res, 2);
    }

    return res;
}

vector<int> fibonacci(int n) {
    if (n == 1 || n == 2) return {1};

    vector<int> a{1}; // F(1)
    vector<int> b{1}; // F(2)

    for (int i = 3; i <= n; ++i) {
        vector<int> c = add(a, b);
        a = b;
        b = c;
    }

    return b;
}

int readInt(const string& prompt, int minValue) {
    int x;

    while (true) {
        cout << prompt;
        if (cin >> x && x > minValue) {
            return x;
        }

        cout << "Ошибка: число должно быть больше " << minValue
             << ". Повторите ввод.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}