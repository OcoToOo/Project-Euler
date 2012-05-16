#include <iostream>

using namespace std;

int solve() {
    int sum = 0;
    int decimal[6];
    int binary[21];
    for (int i = 1; i <= 999999; ++i) {
        {
            bool b = true;
            int number = i;
            int p = 0;
            while (number) {
                decimal[p++] = number % 10;
                number /= 10;
            }
            int middle = p / 2;
            for (int j = 0; j < middle; ++j) {
                if (decimal[j] != decimal[p - 1 - j]) {
                    b = false;
                    break;
                }
            }
            if (!b) continue;
        }
        {
            bool b = true;
            int number = i;
            int p = 0;
            while (number) {
                binary[p++] = number % 2;
                number /= 2;
            }
            int middle = p / 2;
            for (int j = 0; j < middle; ++j) {
                if (binary[j] != binary[p - 1 - j]) {
                    b = false;
                    break;
                }
            }
            if (!b) continue;
        }
        sum += i;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 872187
