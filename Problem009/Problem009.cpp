#include <iostream>

using namespace std;

int solve() {
    int b = 2;
    while (true) {
        if ((500000 - 1000 * b) % (1000 - b) == 0) break;
        b++;
    }
    int a = (500000 - 1000 * b) / (1000 - b);
    int c = 1000 - a - b;
    return a * b * c;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 31875000
