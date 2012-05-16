#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define MAX 1000

using namespace std;

// a x b = c
void multiply(const vector<int>& a, int b, vector<int>& c) {
    c.clear();
    int carry = 0;
    int size = a.size();
    for (int i = 0; i < size; ++i) {
        int product = carry + a[i] * b;
        carry = product / 10;
        c.push_back(product % 10);
    }
    while (carry) {
        c.push_back(carry % 10);
        carry /= 10;
    }
}

// a + b = c
void add(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    c.clear();
    int carry = 0;
    int alen = a.size();
    int blen = b.size();
    for (int i = 0; i < alen || i < blen; ++i){
        int an = 0;
        int bn = 0;
        if (i < alen) an = a[i];
        if (i < blen) bn = b[i];
        int sum = carry + an + bn;
        carry = sum / 10;
        c.push_back(sum % 10);
    }
    while (carry) {
        c.push_back(carry % 10);
        carry /= 10;
    }
}

// a - b = c
bool diff(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    bool plus = true;
    c.clear();
    vector<int> newa = a;
    vector<int> newb = b;
    if (a.size() < b.size()) {
        plus = false;
        newa = b;
        newb = a;
    } else if (a.size() == b.size()) {
        int asum = 0;
        int bsum = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            asum = asum * 10 + a[i];
            bsum = bsum * 10 + b[i];
        }
        if (bsum > asum) {
            plus = false;
            newa = b;
            newb = a;
        }
    }
    vector<int>::iterator a_itr = newa.begin();
    vector<int>::iterator b_itr = newb.begin();
    while (a_itr != newa.end()) {
        int a_digit = *a_itr++; 
        int b_digit = 0;
        if (b_itr != newb.end()) {
            b_digit = *b_itr;
            b_itr++;
        }
        if (a_digit < b_digit) {
            a_digit += 10;
            vector<int> tmp_a(a_itr, newa.end());
            vector<int> tmp_b(1, 1); 
            diff(tmp_a, tmp_b, newa);
            newb.assign(b_itr, newb.end());
            a_itr = newa.begin();
            b_itr = newb.begin();
        }
        c.push_back(a_digit - b_digit);
    }
    return plus;
}

// a ^ b = c
void power(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    c.clear();
    int a_size = a.size();
    int b_size = b.size();
    vector<int> carry;
    vector<int> number;
    for (int i = 0; i < b_size; ++i) {
        int b_digit =  b[i];
        vector<int> d;
        multiply(a, b_digit, d);
        vector<int> e;
        add(d, carry, e);
        c.push_back(e[0]);
        if (e.size() >= 2) {
            carry.assign(e.begin() + 1, e.end());
        }
    }
    for (int i = 0; i < carry.size(); ++i) {
        c.push_back(carry[i]);
    }
    return ;
}

bool judge(int d, const vector<int> numbers, int& size) {
    vector<int> x;
    x.push_back(1);
    vector<int> y;
    y.push_back(*(numbers.end() - 1));
    for (int j = numbers.size() - 1; j >= 1; --j) {
        vector<int> tmp = y;
        vector<int> z;
        multiply(y, numbers[j - 1], z);
        add(z, x, y);
        x = tmp;
    }
    vector<int> tmp = y;
    y = x;
    x = tmp;
    vector<int> x2;
    power(x, x, x2);
    vector<int> y2;
    power(y, y, y2);
    vector<int> dy2;
    multiply(y2, d, dy2);
    vector<int> x2_dy2;
    bool b = diff(x2, dy2, x2_dy2);
    if (!b) return false;
    if (x2_dy2[0] != 1) return false;
    for (int i = 1; i < x2_dy2.size(); ++i) {
        if (x2_dy2[i] != 0) return false;
    }
    size = x.size();
    return true;
}

int solve() {
    int max = 0;
    int ret = 0;
    for (int d = 2; d <= MAX; d++) {
        vector<int> numbers;
        double squareRoot = sqrt((double)d);
        int floorNumber = (int)floor(squareRoot);
        if (ceil(squareRoot) == floorNumber) continue;
        numbers.push_back(floorNumber);
        int a = 1;
        int b = floorNumber;
        bool br = false;
        int size = 0;
        for ( ; ; ) {
            a = (d - b * b) / a;
            int n = (int)((squareRoot + b) / a);
            b = a * n - b;
            if (a == 1 && b == floorNumber) br = true;
            if (br && judge(d, numbers, size)) break;
            numbers.push_back(n);
        }
        if (size >= max) {
            max = size;
            ret = d;
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 661
