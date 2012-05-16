#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 28123

vector<int> abundants;

bool b[MAX + 1];

bool isAbundant(int number) {
    int sum = 1;
    int max = sqrt((double)number);
    for (int i = 2; i <=  max; ++i) {
        if (!(number % i)) {
            sum += i;
            int quotient = number / i;
            if (quotient != i) sum +=quotient;
        }
    }
    return sum > number;
}

int solve() {
    for (int i = 1; i <= MAX; ++i) {
        if (isAbundant(i)) abundants.push_back(i);
    }
    fill(b, b + MAX, false);
    int num = abundants.size();
    for (int i = 0; i < num; ++i) {
        for (int j = i; j < num; ++j) {
            int sum = abundants[i] + abundants[j];
            if (sum > MAX) break; 
            b[sum] = true;
        }
    }
    int sum = 0;
    for (int i = 1; i <= MAX; ++i) {
        if (!b[i]) sum += i;
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 4179871
