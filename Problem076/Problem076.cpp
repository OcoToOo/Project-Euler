#include <iostream>
#include <utility>
#include <map>

using namespace std;

typedef pair<int, int> PII;

map<PII, int> memo;

int func(int n, int m) {
    if (m > n) m = n;
    map<PII, int>::iterator itr = memo.find(PII(n, m));
    if (itr != memo.end()) return itr->second;
    int num = 0;
    for (int i = m; i >= 1; --i) {
        int l = n - i;
        if (l == 0 || l == 1) {
            num += 1;
        } else {
            num += func(l, i);;
        }
    }
    memo.insert(make_pair(make_pair(n, m), num));
    return num;
}

int solve() {
    return func(100, 100 - 1);
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 190569291
