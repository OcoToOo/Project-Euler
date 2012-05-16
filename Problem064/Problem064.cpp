#include <iostream>
#include <math.h>

using namespace std;

int solve() {
    int sum = 0;
    for (int number = 1; number <= 10000; number++) {
        double squareRoot = sqrt(static_cast<double>(number));
        int floorNumber = static_cast<int>(floor(squareRoot));
        if (static_cast<int>(ceil(squareRoot)) == floorNumber) continue;
        int numerator = floorNumber;
        int denominator = 1;
        int num = 0;
        do {
            denominator = (number - numerator * numerator) / denominator;
            int n = (squareRoot + numerator) / denominator;
            numerator = denominator * n - numerator;
            num++;

        } while (denominator != 1);
        if (num % 2) sum++;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 1322
