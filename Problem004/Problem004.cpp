#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int n){
    vector<int> v;
    while (n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    int len = v.size();
    int mid = len / 2;
    for (int i = 0; i < mid; ++i){
        if (v[i] != v[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int solve() {
    int max = 0;
    int min = 100;
    for (int i = 999; i >= min; --i) {
        for (int j = i; j >= min; --j) {
            int p = i * j;
            if (isPalindrome(p)){
                if (p > max) {
                    max = p;
                    min = j;
                }
                break;
            }
        }
    }
    return max;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 906609
