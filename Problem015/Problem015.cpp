#include <iostream>

using namespace std;

typedef long long LL;

#define L 20

LL solve(){
    LL n[L];
    LL d[L];
    bool b[L];
    for (int i = 0; i < L; ++i){
        n[i] = L * 2 - i;
        d[i] = L - i;
        b[i] = false;
    }
    for (int i = 0; i < L; ++i) {
        LL numerator = n[i];
        for (int j = 0; j < L; ++j) {
            if (b[j]) continue;
            LL denominator = d[j];
            if (numerator % denominator == 0){
                n[i] = numerator / denominator;
                b[j] = true;
                break;
            }
        }
    }
    LL numerator = 1;
    LL denominator = 1;
    for (int i = 0; i < L; ++i) {
        numerator *= n[i];
        if (!b[i]) denominator *= d[i];
    }
    return numerator / denominator;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 137846528820
