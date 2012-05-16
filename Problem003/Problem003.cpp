#include <iostream>

using namespace std;

typedef long long ll;

int solve() {
    ll n = 600851475143;
    int i = 2;
    for ( ; static_cast<ll>(i * i) <= n; ++i){
        while (n % i == 0){
            n /= i;
        }
    }
    return n == 1 ? i : n;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 6857
