#include <iostream>

using namespace std;

int solve() {
    int denominator = 1;
    int numerator = 1;
    for (int d = 11; d <= 99; ++d) {
        if (d % 10 == 0) continue;
        int a[2];
        a[0] = d % 10;
        a[1] = d / 10;
        for (int n = 11; n < d; ++n) {
            if (n % 10 == 0) continue;
            int b[2];
            b[0] = n % 10;
            b[1] = n / 10;
            if (a[1] == b[0]) {
                if ((double)b[1] / a[0] == (double)n / d){
                    numerator *= n;
                    denominator *= d;
                }
            }
        }
    }
    for (int i = 2; i <= numerator; ++i){
        while (numerator % i == 0 && denominator % i == 0){
            numerator /= i;
            denominator /= i;
        }
    }
    return denominator;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 100
