#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

void todigit(int number, vector<int>& digits) {
    for (int place = 0; number; ++place) {
        digits[place] = number % 10;
        number /= 10;
    }
    sort(digits.begin(), digits.end());
    return ;
}

int solve() {
    for (int len = 2; ; ++len) {
        vector<int> d(len);
        vector<int> m(len);
        int min = static_cast<int>(pow(10.0, static_cast<double>(len - 1)));
        int max = static_cast<int>(pow(10.0, (double)(len)) - 1) / 6;
        for (int number = min; number <= max; number++) {
            todigit(number, d);
            bool b = true;
            for (int i = 2; i <= 6; ++i) {
                todigit(number * i, m);
                if (d != m) {
                    b = false;
                    break;
                }
            }
            if (b) return number;
        }
    }
}

int main(){
    cout << solve() << endl;
    return 0;
}

// Answer: 142857
