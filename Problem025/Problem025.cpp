#include <iostream>
#include <vector>

using namespace std;

vector<int> f;
vector<int> f1;
vector<int> f2;

int solve() {
    int term = 2;
    f1.push_back(1);
    f2.push_back(1);
    while (true) {
        vector<int>::iterator f1Itr = f1.begin();
        vector<int>::iterator f1ItrEnd = f1.end();
        vector<int>::iterator f2Itr = f2.begin();
        vector<int>::iterator f2ItrEnd = f2.end();
        int carry = 0;
        f.clear();
        for ( ; f1Itr != f1ItrEnd; ++f1Itr) {
            int f1Digit = *f1Itr;
            int f2Digit = 0;
            if (f2Itr != f2ItrEnd) {
                f2Digit = *f2Itr;
                f2Itr++;
            }
            int sum = carry + f1Digit + f2Digit;
            carry = sum / 10;
            f.push_back(sum % 10);
        }
        while (carry) {
            f.push_back(carry % 10);
            carry /= 10;
        }
        term++;
        if (f.size() >= 1000) break;
        f2 = f1;
        f1 = f;
    }
    return term;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 4782
