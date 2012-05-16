#include <iostream>

using namespace std;

int factor[10];

void init(){
    factor[0] = 1;
    factor[1] = 1;
    for (int i = 2; i <= 9; ++i){
        factor[i] = factor[i - 1] * i;
    }
}

int solve() {
    init();
    int a = factor[9];
    int b = 0;
    int c = 1;
    do {
        b += a;
        c *= 10;
    } while (c <= b);
    int max = c - 1;
    int ret = 0;
    for (int i = 3; i <= max; ++i) {
        int number = i;
        int sum = 0;
        while (number) {
            sum += factor[number % 10];
            if (sum > i) break;
            number /= 10;
        }
        if (sum == i) ret += i;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 40730
