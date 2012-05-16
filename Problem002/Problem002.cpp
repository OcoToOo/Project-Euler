#include <iostream>

using namespace std;

int solve() {
    int sum = 2;
    int a[2];
    a[0] = 1;
    a[1] = 2;
    while (true) {
        int value = a[0] + a[1];		
        if (value > 400 * 10000) break;
        a[0] = a[1];
        a[1] = value;
        if (value % 2 == 0)	sum += value;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    getchar();
    return 0;
}

// Answer: 4613732
