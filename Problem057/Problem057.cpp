#include <iostream>
#include <vector>

using namespace std;

void calc_denominator(vector<int>& pre_d, vector<int>& pre_n, vector<int>& d) {
    int carry = 0;
    vector<int> tmp;
    int len1 = pre_d.size();
    for (int i = 0; i < len1; ++i) {
        int product = carry + pre_d[i] * 2;
        carry = product / 10;
        tmp.push_back(product % 10);
    }
    while (carry) {
        tmp.push_back(carry % 10);
        carry /= 10;
    }
    carry = 0;
    int len2 = tmp.size();
    int len3 = pre_n.size();
    for (int i = 0; i < len2 || i < len3; ++i) {
        int a = 0;
        if (i < len2) a = tmp[i];
        int b = 0;
        if (i < len3) b = pre_n[i];
        int sum = carry + a + b;
        carry = sum / 10;
        d.push_back(sum % 10);
    }
    while (carry) {
        d.push_back(carry % 10);
        carry /= 10;
    }
    return ;
}

void calc_numerator(vector<int>& pre_d, vector<int>& d, vector<int>& n) {
    int len1 = pre_d.size();
    int len2 = d.size();
    int carry = 0;
    for (int i = 0; i < len1 || i < len2; ++i) {
        int a = 0;
        if (i < len1) a = pre_d[i];
        int b = 0;
        if (i < len2) b = d[i];
        int sum = carry + a + b;
        carry = sum / 10;
        n.push_back(sum % 10);
    }
    while (carry) {
        n.push_back(carry % 10);
        carry /= 10;
    }
    return ;
}

int solve() {
    int num = 0;
    vector<int> pre_numerator;
    vector<int> pre_denominator;
    pre_numerator.push_back(1);
    pre_denominator.push_back(2);
    for (int term = 1; term <= 1000; ++term) {
        vector<int> denominator;
        calc_denominator(pre_denominator, pre_numerator, denominator);
        vector<int> numerator;
        calc_numerator(pre_denominator, denominator, numerator);
        if (numerator.size() > denominator.size()) num++;
        pre_numerator = pre_denominator;
        pre_denominator = denominator;
    }
    return num;
}

int main(){
    cout << solve() << endl;
    return 0;
}

// Answer: 153
