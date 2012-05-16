#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

// number * a = number
void multiply(vector<int>& number, int a) {
    vector<int> product;
    int carry = 0;
    int size = number.size();
    for (int i = 0; i < size; ++i) {
        int p = carry + number[i] * a;
        product.push_back(p % 10);
        carry = p / 10;
    }
    while (carry) {
        product.push_back(carry % 10);
        carry /= 10;
    }
    number = product;
    return ;
}

int solve() {
    int num = 0;
    for (int a = 2; a <= 100; ++a) {
        vector<int> digits;
        digits.push_back(1);
        for (int b = 1; b <= 100; ++b) {
            multiply(digits, a);
            if (b == 1) continue;
            v.push_back(digits);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 9183
