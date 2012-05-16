#include <iostream>

using namespace std;

int solve() {
    int sum = 1;
    for (int i = 2; i <= 501; ++i) {
        int a = 2 * i - 1;
        int b = 4 * i * i - 4 * i + 1;
        sum += 4 * b - 6 * a + 6;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 669171001
