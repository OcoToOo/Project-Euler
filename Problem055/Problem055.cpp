#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int>& number) {
    vector<int> rev = number;
    reverse(rev.begin(), rev.end());
    vector<int> sum;
    int carry = 0;
    int size = number.size();
    for (int i = 0; i < size; ++i){
        int p = carry + number[i] + rev[i];
        carry = p / 10;
        sum.push_back(p % 10);
    }
    if (carry != 0) sum.push_back(carry);
    number = sum;
    return ;
}

int solve() {
    int num = 0;

    for (int i = 1; i < 10000; ++i) {
        int number = i;
        vector<int> digits;
        while (number) {
            digits.push_back(number % 10);
            number /= 10;
        }

        int cnt;
        for (cnt = 1; cnt < 50; ++cnt) {
            func(digits);
            vector<int> rev = digits;
            reverse(rev.begin(), rev.end());
            if (digits == rev) break;
        }
        if (cnt >= 50) num++;
    }

    return num;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 249
