#include <iostream>
#include <math.h>

using namespace std;

int divisor(int number) {
    int num = 0;
    int max = (int)sqrt((double)number);
    for (int i = 1; i <= max; ++i) {
        if (number % i == 0) {
            if (i == max) {
                num++;
            } else {
                num += 2;
            }
        }
    }
    return num;
}

int solve() {
    int triangle = 0;
    int index = 1;
    int num = 0;
    while (num < 501) {
        triangle += index;
        num = divisor(triangle);
        index++;
    }
    return triangle;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 76576500
