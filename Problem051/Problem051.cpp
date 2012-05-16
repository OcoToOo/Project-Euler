#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define TARGET 8

bool isPrime(int n) {
    if (n % 2 == 0) return false;
    int max = (int)(sqrt((double)n));
    for (int i = 3; i <= max; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solve(){
    for (int len = 5; ; ++len) {
        int a = (1 << len) - 2;
        for (int i = 1; i <= a; ++i) {
            vector<int> bits(len, 0);
            int num = 0;
            for (int b = 0; b < len; ++b){
                if (1 << b & i){
                    bits[b] = 1;
                    num++;
                }
            }
            int min = (int)(pow(10.0, (double)(len - num - 1)));
            int max = (int)(pow(10.0, (double)(len - num))) - 1;
            for (int base = min; base <= max; ++base) {
                vector<int> v(len, 0);
                int index = 0;
                int tmp = base;
                while (tmp) {
                    while (bits[index] != 0){
                        index++;
                    }
                    v[index++] = tmp % 10;
                    tmp /= 10;
                }
                for (int change = 0, cnt = 0, answer = 0; change <= 9; ++change) {
                    for (int i = 0; i < len; ++i) {
                        if (bits[i]) v[i] = change;
                    }
                    if (v[0] == 0) continue;
                    int number = 0;
                    for (int i = 0; i < v.size(); ++i) {
                        number = number * 10 + v[i];
                    }
                    if (isPrime(number)) {
                        if (cnt == 0) answer = number;
                        cnt++;
                    }
                    if (cnt == TARGET) return answer;
                    if (10 - (change + 1) < TARGET - cnt) break;
                }
            }
        }
    }

}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 121313
