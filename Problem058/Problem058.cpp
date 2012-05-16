#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
    int max = sqrt((double)n);
    for (int i = 2; i <= max; ++i){
        if (n % i == 0) return false;
    }
    return n != 1;
}

int solve() {
    int sum = 1;
    int num = 0;
    int len = 0;
    for (int i = 2; ; ++i) {
        len = 2 * i - 1;
        int base = 4 * i * i - 4 * i + 1;
        for (int j = 3; j >= 0; --j) {
            int number = base - j * (len - 1);
            if (isPrime(number)) num++;
        }
        sum += 4;
        if ((num * 100 / sum) < 10) break;
    }
    return len;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 26241
