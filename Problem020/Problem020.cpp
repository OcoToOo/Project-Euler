#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve() {
    vector<int> digits;
    digits.push_back(1);
    for (int i = 1; i <= 100; ++i) {
        int carry = 0;
        vector<int> products;
        int len = digits.size();
        for (int j = 0; j < len; ++j) {
            int product = carry + digits[j] * i;
            carry = product / 10;
            products.push_back(product % 10);
        }
        while (carry) {
            products.push_back(carry % 10);
            carry /= 10;
        }
        digits = products;
    }
    return accumulate(digits.begin(), digits.end(), 0);
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 648
