#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;

int prime[2000000 + 1]; 
int isprime[2000000 + 1]; 

int sieve(){
    fill(isprime, isprime + 2000000 + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    int p = 0;
    for (int i = 2; i <= 2000000; ++i){
        if (isprime[i]){
            prime[p++] = i;
            for (int j = 2 * i; j <= 2000000; j += i){
                isprime[j] = false;
            }
        }
    }
    return p;
}

int main(){
    cout << accumulate(prime, prime + sieve(), 0LL) << endl;
    return 0;
}

// Answer: 142913828922
