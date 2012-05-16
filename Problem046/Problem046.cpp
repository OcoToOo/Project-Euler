#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    int max = (int)(sqrt((double)n));
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve() {
    vector<int> primes;
    primes.push_back(2);
    // odd
    int number = 3;
    for ( ; ; number += 2) {
        // not prime
        if (isPrime(number)) {
            primes.push_back(number);
            continue;
        }
        bool b = false;
        for (int j = 1; ; ++j) {
            int square = (int)pow((double)j, 2.0);
            int canditate = number - square * 2;
            if (canditate < 2) break;
            if (find(primes.begin(), primes.end(), canditate) != primes.end()){
                b = true;
                break;
            }
        }
        if (!b) break;
    }
    return number;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 5777
