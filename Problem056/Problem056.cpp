#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int>& number, int a) {
    vector<int> product;
    int sum = 0;
    int carry = 0;
    int size = number.size();
    for (int i = 0; i < size; ++i) {
        int p = carry + number[i] * a;
        int d = p % 10;
        product.push_back(d);
        sum += d;
        carry = p / 10;
    }
    while (carry){
        int d = carry % 10;
        product.push_back(d);
        sum += d;
        carry /= 10;
    }
    number = product;
    return sum;
}

int solve() {
    int ret = 0;
    for (int a = 1; a <= 100; ++a) {
        vector<int> number;
        number.push_back(1);
        for (int b = 1; b <= 100; ++b) {
            ret = max(ret, func(number, a));
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 972
