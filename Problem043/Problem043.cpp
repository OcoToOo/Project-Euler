#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL tointeger(int n[10], int s, int len){
    LL a = 0;
    for (int i = 0; i < len; ++i){
        a = a * 10LL + n[i + s];
    }
    return a;
}

LL solve(){
    int n[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    int m[] = {2, 3, 5, 7, 11, 13, 17};
    LL sum = 0LL;
    do {
        bool b = true;
        for (int i = 2; i <= 8; ++i) {
            if (tointeger(n, i - 1, 3) % m[i - 2]) {
                b = false;
                break;
            }
        }
        if (b) sum += tointeger(n, 0, 10);
    } while (next_permutation(n, n + 10));
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 16695334890
