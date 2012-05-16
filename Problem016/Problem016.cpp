#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int solve(){
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < 1000; ++i){
        int carry = 0;
        vector<int> tmp;
        int len = v.size();
        for (int l = 0; l < len; ++l) {
            int value = carry + v[l] * 2;
            tmp.push_back(value % 10);
            carry = value / 10;
        }
        if (carry != 0) tmp.push_back(carry);
        v = tmp;
    }
    return accumulate(v.begin(), v.end(), 0);
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 1366
