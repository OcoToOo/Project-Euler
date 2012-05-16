#include <iostream>

using namespace std;

typedef long long LL;

LL solve() {
    LL t = 286;
    LL p = 166;
    LL h = 144;
    LL number = 40756;
    while (true) {

        while (true) {
            LL product = t * t + t;
            if (product == number * 2) break;
            if (product > number * 2) {
                number = product / 2;
                break;
            }
            t++;
        }

        bool b = true;

        while (true) {
            LL product = 3 * p * p - p;
            if (product == number * 2) break;
            if (product > number * 2) {
                number = product / 2 + product % 2;
                b = false;
                break;
            }
            p++;
        }
        if (!b) continue;

        while (true) {
            LL product = 2 * h * h - h;
            if (product == number) break;
            if (product > number) {
                number = product;
                b = false;
                break;
            }
            h++;
        }
        if (!b) continue;

        break;
    }

    return number;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 1533776805
