#include <iostream>
#include <math.h>

using namespace std;

int solve() {
    int sumOfTheSquares = 0;
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;
        sumOfTheSquares += (int)pow((double)i, 2.0);
    }
    int squareOfTheSum = (int)pow((double)sum, 2.0);
    return abs(sumOfTheSquares - squareOfTheSum);
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 25164150
