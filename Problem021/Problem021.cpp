#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool canditate[10000];

int sums[10000];

int divisor(int number) {
    int max = (int)sqrt((double)number);
    int sum = 1;
    for (int i = 2; i <= max; ++i) {
        if (number % i == 0) {
            int quotient = number / i;
            sum += i;
            if (i != max) sum += quotient;
            if (sum >= 10000) return 0;
        }
    }
    canditate[number] = true;
    return sum;
}

int solve() {
    fill(canditate, canditate + 10000, false);
    for (int i = 1; i < 10000; ++i) {
        sums[i] = divisor(i);
    }
    int ret = 0;
    for (int i = 1; i < 10000; ++i) {
        if (!canditate[i]) continue;
        for (int j = 1; j < 10000; ++j) {
            if (i == j || !canditate[j]) continue;
            if ((i == sums[j]) && (j == sums[i])) {
                ret += i;
                ret += j;
                canditate[i] = false;
                break;
            }
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 31626
