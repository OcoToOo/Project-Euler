#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    int max = sqrt((double)n);
    for (int i = 2; i <= max; ++i){
        if (!(n % i)) return false;
    }
    return true;
}

int func(int a, int b) {
    int n = 0;
    while (true) {
        int value = n * n + a * n + b;
        if (value < 2) break;
        if (!isPrime(value))break;
        n++;
    }
    return n + 1;
}

int solve() {
    int max = 0;
    int maxa = 0;
    int maxb = 0;
    for (int a = -999; a <= 999; ++a) {
        for (int b = -999; b <= 999; ++b) {
            int num = func(a, b);
            if (num > max) {
                max = num;
                maxa = a;
                maxb = b;
            }
        }
    }
    return maxa * maxb;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: -59231
