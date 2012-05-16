#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

#define TAEGET 60

int factorials[10];

void init() {
    factorials[0] = 1;
    for (int i = 1; i <= 9; i++) {
        factorials[i] = factorials[i - 1] * i;
    }
}

int getSum(int n) {
    int sum = 0;
    while (n) {
        sum += factorials[n % 10];
        n /= 10;
    }
    return sum;
}

int solve() {
    init();
    map<int, int> m;
    m.insert(PII(169, 3));
    m.insert(PII(871, 2));
    m.insert(PII(872, 2));
    int num = 0;
    for (int i = 1; i <= 999999; i++) {
        int number = i;
        vector<int> numbers;
        while (true) {
            map<int, int>::iterator itr = m.find(number);
            if (itr != m.end()) {
                int size = numbers.size();
                int circle = size + itr->second;
                if (circle == TAEGET) num++;
                for (int j = 0; j < size; j++) {
                    m.insert(PII(numbers[j], size - j + itr->second));
                }
                break;
            }
            numbers.push_back(number);
            int sum = getSum(number);
            if (sum == number) {
                int circle = numbers.size();
                if (circle == TAEGET) num++;
                for (int j = 0; j < circle; j++) {
                    m.insert(PII(numbers[j], circle - j));
                }
                break;
            }
            number = sum;
        }
    }
    return num;
}

int main() {
    cout << solve() << endl;
    getchar();
    return 0;
}

// Answer: 402
