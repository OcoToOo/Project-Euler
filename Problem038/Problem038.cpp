#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int func(int number) {
    int len = 0;
    while (number) {
        len++;
        number /= 10;
    }
    return len;
}

int solve() {
    int ret = 0;
    int number = 1;
    int digits[9];
    for (int number = 1; ; ++number){
        int totalLen = 0;
        int i = 1;
        for ( ; ; ++i) {
            int t = totalLen;
            int product = number * i;
            int len = func(product);
            totalLen += len;
            if (totalLen > 9) break;
            bool b = true;
            for (int j = 0; j < len; ++j) {
                int p = (int)(pow(10.0, (double)(len - 1 - j)));
                int digit = product / p;
                if (digit == 0) {
                    b = false;
                    break;
                }
                product %= p;
                for (int k = 0; k < t; ++k) {
                    if (digit == digits[k]) {
                        b = false;
                        break;
                    }
                }
                if (!b) break;
                digits[t++] = digit;
            }
            if (!b) break;
            if (totalLen == 9 && i > 1) {
                int pandigital = 0;
                for (int j = 0; j < 9; ++j) {
                    pandigital = pandigital * 10 + digits[j];
                }
                ret = max(ret, pandigital);
                break;
            }
        }
        if (i == 2 && totalLen > 9) break;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 932718654
