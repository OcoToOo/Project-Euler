#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> primefactor(int n){
    map<int, int> factor;
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0){
            factor[i] += i;
            n /= i;
        }
    }
    if (n != 1) factor[n] += n;
    return factor;
}

int solve(){
    int cnt = 0;
    int ret = 0;
    set<int> primefactors;
    for (int i = 2; ; i++){
        map<int, int> m = primefactor(i);
        if (m.size() != 4) {
            cnt = 0;
            primefactors.clear();
            continue;
        }
        if (cnt == 0) ret = i;
        cnt++;
        for (map<int, int>::iterator itr = m.begin(); itr != m.end(); ++itr){
            primefactors.insert(itr->second);
        }
        if (primefactors.size() != cnt * 4){
            cnt = 0;
            primefactors.clear();
            continue;
        }
        if (cnt == 4) break;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    getchar();
    return 0;
}

// Answer: 134043
