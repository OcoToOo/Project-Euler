#include <iostream>

using namespace std;

int solve() {
    int max = 0;
    int ret = 0;
    for (int p = 1; p <= 1000; ++p) {
        int num = 0;
        for (int a = 1; a <= 999; ++a) {
            int numerator = 2 * a - p;
            if (numerator == 0) break;
            int denominator = 2 * a - 2 * p;
            if (denominator == 0) break;
            int remainder = p * numerator % denominator;
            if (remainder != 0) continue;
            int b = p * numerator / denominator;
            if (b < 0) continue;
            if (a + b >= p) continue;
            num++;
        }
        if (num > max) {
            max = num;
            ret = p;
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 840
