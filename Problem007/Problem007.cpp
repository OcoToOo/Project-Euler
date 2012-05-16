#include <vector>
#include <iostream>

using namespace std;

int v[10001];

bool isPrime(int n, int num) {
    bool b = true;
    for (int i = 0; i < num; ++i) {
        if (n % v[i] == 0) {
            return false;
        }
    }
    return true;
}

int solve() {
    int num = 0;
    int n = 2;
    for ( ; ; ++n) {
        if (isPrime(n, num)){
            num++;
            if (num >= 10001) break;
            v[num - 1] = n;
        }
    }
    return n;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 104743
