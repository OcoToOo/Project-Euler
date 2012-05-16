#include <iostream>
#include <algorithm>

using namespace std;

int n[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve() {
    int cnt = 0;
    for (int i = 0; i < 1000000 - 1; ++i) {
        next_permutation(n, n + 10);
    }
}

int main() {
    solve();
    for (int i = 0; i < 10; ++i){
        cout << n[i];
    }
    cout << endl;
    return 0;
}

// Answer: 2783915460
