#include <iostream>
#include <vector>

using namespace std;

// b = a ^ a
void power(int a, int b[]) {
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < a; ++i) {
        vector<int> tmp;
        int carry = 0;
        for (int j = 0; j < v.size(); ++j) {
            int n = v[j];
            int p = carry + n * a;
            carry = p / 10;
            tmp.push_back(p % 10);
            if (tmp.size() >= 10) break;
        }
        while (carry) {
            if (tmp.size() >= 10) break;
            tmp.push_back(carry % 10);
            carry /= 10;
        }
        v = tmp;
    }
    for (int i = 0; i < v.size(); ++i) {
        b[i] = v[i];
    }
    return ;
}

void add(int a[][10], int b[]) {
    int carry = 0;
    for (int i = 0; i < 10; ++i) {
        int sum = carry;
        for (int j = 0; j < 1000; ++j) {
            sum += a[j][i];
        }
        b[i] = sum % 10;
        carry = sum / 10;
    }
    return ;
}

void solve() {
    int n[1000][10];
    for (int i = 1; i <= 1000; ++i) {
        fill(n[i - 1], n[i - 1] + 10, 0);
        power(i, n[i - 1]);
    }
    int sum[10];
    add(n, sum);
    for (int i = 9; i >= 0; --i) {
        cout << sum[i];
    }
    cout << endl;
}

int main(){
    solve();
    return 0;
}

// Answer: 9110846700
