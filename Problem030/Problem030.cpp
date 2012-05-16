#include <iostream>
#include <math.h>

using namespace std;

int solve() {
    int a = 0;
    int b = 1;
    int c = static_cast<int>(pow(9.0, 5.0));
    do {
        a += c;
        b *= 10;
    } while (b <= a);
    int max = b - 1;
    int ret = 0;
    for (int i = 2; i <= max; ++i) {
        int number = i;
        int sum = 0;
        while (number) {
            double digit = number % 10;
            sum += static_cast<int>(pow(digit, 5.0));
            number /= 10;
        }
        if (sum == i) ret += i;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 443839
