#include <iostream>
#include <math.h>

using namespace std;

// n >= 2
bool isPrime(int n) {
    int max = (int)(sqrt((double)n));
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve() {
    int ret = 3; // 2, 3, 5
    int digits[6];
    for (int i = 6; i <= 999999; ++i) {
        int number = i;
        int len = 0;
        while (number) {
            digits[len++] = number % 10;
            number /= 10;
        }
        int sum = 0;
        bool circular = true;
        for (int j = 0; j < len; ++j) {
            int digit = digits[j];
            if (digit == 0 || digit == 5 || digit % 2 == 0) {
                circular = false;
                break;
            }
            sum += digit;
        }
        if (!circular || sum % 3 == 0) continue;
        for (int j = 0; j < len; ++j) {
            int replace = 0;
            if (j == 0) {
                replace = i;
            } else {
                for (int k = j; k < len; ++k) {
                    replace = replace * 10 + digits[len - 1 - k];
                }
                for (int k = 0; k < j; ++k) {
                    replace = replace * 10 + digits[len - 1 - k];
                }
            }
            if (!isPrime(replace)) {
                circular = false;
                break;
            }
        }
        if (circular) ret++;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 55
