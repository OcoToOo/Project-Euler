#include <iostream>
#include <math.h>

using namespace std;

int func(int number) {
    int len = 0;
    while (number) {
        len++;
        number /= 10;
    }
    return len;
}

int solve() {
    int ret = 1;
    int target = 1;
    int totalLen = 0;
    for (int i = 1; ; ++i){
        int len = func(i);
        if (totalLen + len >= target) {
            int targetPlace = target - totalLen;
            int place = 1;
            int number = i;
            while (true) {
                int p = (int)pow(10.0, (double)(len - 1));
                if (place == targetPlace) {
                    ret *= number / p;
                    break;
                }
                len--;
                place++;
                number %= p;
            }
            if (target == 100000) break;
            target *= 10;
        }
        totalLen += len;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 210
