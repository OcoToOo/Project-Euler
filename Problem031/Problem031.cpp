#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

#define N 200

int coins[] = {200, 100, 50, 20, 10, 5, 2, 1};

map<PII, int> m;

int solve(int index, int total){
    if (index == 7) return 1;
    map<PII, int>::iterator itr = m.find(PII(index, total));
    if (itr != m.end()) return itr->second;
    int value = coins[index];
    int sum = 0;
    for (int i = 0; i <= total / value; ++i){
        sum += solve(index + 1, total - value * i);
    }
    m.insert(pair<PII, int>(PII(index, total) , sum));
    return sum;
}

int main() {
    cout << solve(0, N) << endl;
    return 0;
}

// Answer: 73682
