#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    int max = (int)(sqrt((double)n));
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) return false;
    }
    return n >= 2;
}

int solve() {
    int num = 0;
    int sum = 0;
    for (int i = 10; ; ++i){
        int len = 0;
        {
            bool b = true;
            int number = i;
            while (true) {
                if (!isPrime(number)) {
                    b = false;
                    break;
                }
                len++;
                number /= 10;
                if (number == 0) break;
            }
            if (!b) continue;
        }
        {
            bool b = true;
            int number = i;
            while (true) {
                number %= (int)pow(10.0, (double)(len - 1));
                if (!isPrime(number)) {
                    b = false;
                    break;
                }
                len--;
                if (len == 1) break;
            }
            if (!b) continue;
        }
        sum += i;
        num++;		
        if (num >= 11) break;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 748317
