#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(int number) {
    int max = (int)(sqrt((double)number));
    for (int i = 2; i <= max; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return number > 1;
}

vector<int> solve() {
    vector<int> v;
    for (int i = 9; i >= 1; --i){
        v.clear();
        for (int j = i; j >= 1; --j){
            v.push_back(j);
        }
        do {
            int n = 0;
            for (int j = 0; j < i; ++j){
                n = n * 10 + v[j];
            }
            if (isPrime(n)) goto end;
        } while (prev_permutation(v.begin(), v.end()));
    }
end:
    return v;
}

int main() {
    const vector<int> v = solve();
    for (int i = 0; i < v.size(); ++i){
        cout << v[i];
    }
    cout << endl;
    return 0;
}

// Answer: 7652413
