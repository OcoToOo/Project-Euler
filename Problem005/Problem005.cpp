#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return (a * b / gcd(a, b));
}

int solve() {
    LL a = 1;
    for (LL b = 1; b <= 20; ++b){
        a = lcm(a, b);
    }
    return a;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 232792560
