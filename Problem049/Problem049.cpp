#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

#define MIN 1000
#define MAX 9999

bool isprime[MAX - MIN + 1]; 
bool isprimesmall[MAX];
vector<int> v[MAX - MIN + 1];

void sieve() {
    int ub = (int)sqrt((double)MAX);
    fill(isprimesmall, isprimesmall + ub + 1, true);
    isprimesmall[0] = false;
    isprimesmall[1] = false;
    fill(isprime, isprime + (MAX - MIN + 1), true);
    for (int i = 2; i <= ub; i++){
        if (isprimesmall[i]){
            int tmp = (int)sqrt((double)MAX);
            for (int j = 2 * i; j <= tmp; j += i){
                isprimesmall[j] = false;
            }
            for (int j = max(2, (MIN + i - 1) / i) * i; j <= MAX; j += i){
                isprime[j - MIN] = false;
            }
        }
    }
}

void todigit(int n, int digits[4]) {
    for (int i = 0; i < 4; i++){
        digits[i] = n % 10;
        n /= 10;
    }
    return ;
}

int tointeger(int digits[4]){
    int n = 0;
    for (int i = 0; i < 4; i++){
        n = n * 10 + digits[i];
    }
    return n;
}

bool judge(vector<int>& v){
    int size = v.size();
    if (size < 3) return false;   
    int first;
    int second;
    int third;
    for (int i = 0; i < size - 2; i++){
        first = v[i];
        for (int j = i + 1; j < size - 1; j++){
            second = v[j];
            for (int k = j + 1; k < size; k++){
                third = v[k];
                if (second - first == third - second) {
                    cout << first << second << third << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    sieve();

    for (int i = 0; i <= MAX - MIN; ++i){
        if (!isprime[i]) continue;
        int a = i + MIN;
        int digits[4];
        todigit(a, digits);
        sort(digits, digits + 4);
        int b = tointeger(digits);
        if (b == 1478) continue;
        v[b].push_back(a);
    }

    for (int i = 0; i <= MAX - MIN; ++i){
        if (judge(v[i])) break;
    }
}

int main(){
    solve();
    return 0;
}

// Answer: 296962999629
