#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

map<PII, int> memo;

#define MAX 100

bool isprime[MAX + 1]; 
vector<int> primes;

void sieve(){
    int p = 0;
    fill(isprime, isprime + (MAX + 1), true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= MAX; i++){
        if (isprime[i]){
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX; j += i) isprime[j] = false;
        }
    }
    return ;
}

int func(int n, int m) {
    if (m > n) m = n;
    if (m <= 1) return 0;
    {
        map<PII, int>::iterator itr = memo.find(PII(n, m));
        if (itr != memo.end()) return itr->second;
    }
    vector<int>::iterator itr;
    for (int i = m; i >= 2; --i) {
        itr = find(primes.begin(), primes.end(), i);
        if (itr != primes.end()) break;
    }
    int num = 0;
    for ( ; ; --itr) {
        int number = *itr;
        if (number == n) {
            num += 1;
        } else {
            num += func(n - number, number);
        }
        if (itr == primes.begin()) break;
    }
    memo.insert(make_pair(make_pair(n, m), num));
    return num;
}

int solve() {
    sieve();
    int number = 1;
    for ( ; ; number++) {
        if (func(number, number - 1) >= 5000) break;
    }
    return number;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 71
