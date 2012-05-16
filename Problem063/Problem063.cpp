#include <iostream>
#include <vector>

using namespace std;

bool func(int a, int b) {
    vector<int> digits;
    digits.push_back(1);
    for (int i = 0; i < b; ++i) {
        vector<int> products;
        int carry = 0;
        int size = digits.size();
        for (int j = 0; j < size; ++j) {
            int product = carry + digits[j] * a;
            carry = product / 10;
            products.push_back(product % 10);
        }
        while (carry) {
            products.push_back(carry % 10);
            carry /= 10;
        }
        digits = products;
    }
    return digits.size() == b;
}

int solve() {
    int num = 0;
    for (int len = 1; ; ++len) {
        bool b = false;
        for (int number = 1; number < 10; ++number) {
            if (func(number, len)) {
                b = true;
                num++;
            }
        }
        if (!b) break;
    }
    return num;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 49
