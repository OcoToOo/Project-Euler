#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// a * b = a
void multiply(vector<int>& a, int b) {
    vector<int> tmp;
    int carry = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        int product = carry + a[i] * b;
        carry = product / 10;
        tmp.push_back(product % 10);
    }
    while (carry) {
        tmp.push_back(carry % 10);
        carry /= 10;
    }
    a = tmp;
}

// a + b = a
void add(vector<int>& a, vector<int>& b) {
    vector<int> tmp;
    int carry = 0;
    int alen = a.size();
    int blen = b.size();
    for (int i = 0; (i < alen || i < blen); i++){
        int an = 0;
        int bn = 0;
        if (i < alen) an = a[i];
        if (i < blen) bn = b[i];
        int sum = carry + an + bn;
        carry = sum / 10;
        tmp.push_back(sum % 10);
    }
    while (carry) {
        tmp.push_back(carry % 10);
        carry /= 10;
    }
    a = tmp;
}

int solve() {
    vector<int> n;
    n.push_back(2);
    for (int i = 0; i < 99; ++i) {
        if (i % 3 == 1) n.push_back((i / 3 + 1) * 2);
        else n.push_back(1);
    }
    vector<int> denominator;
    denominator.push_back(1);
    vector<int> numerator;
    numerator.push_back(*(n.end() - 1));
    for (int j = n.size() - 1; j >= 1; --j) {
        vector<int> tmp = numerator;
        multiply(numerator, n[j - 1]);
        add(numerator, denominator);
        denominator = tmp;
    }
    return accumulate(numerator.begin(), numerator.end(), 0);
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer : 272
