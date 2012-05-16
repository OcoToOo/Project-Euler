#include <iostream>
#include <math.h>
#include <numeric>

using namespace std;

#define N 1000000

int prime[N + 1];
bool isprime[N + 1]; 

bool isPrime(int number) {
    int max = (int)(sqrt((double)number));
    for (int i = 2; i <= max; ++i) {
        if (number % i == 0) return false;
    }
    return number > 1;
}

int sieve(){
    int p = 0;
    fill(isprime, isprime + N, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= N; ++i){
        if (isprime[i]){
            prime[p++] = i;
            for (int j = 2 * i; j <= N; j += i){
                isprime[j] = false;
            }
        }
    }
    return p;
}

int solve() {
    int num = sieve();
    int max = 0;
    int ret;
    for (int s = 0; s < num; ++s){
        int len = max;
        int sum = accumulate(prime + s, prime + s + max, 0);
        for (int i = s + len; i < num; ++i){
            sum += prime[i];
            if (sum >= N) break;
            if (isPrime(sum)) {
                max = i - s + 1;
                ret = sum;
            }
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 997651
