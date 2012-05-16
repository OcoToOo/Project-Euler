#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> primefactor(vector<int> ns){
    map<int, int> factor;
    for (int i = 0; i < ns.size(); i++){
        int n = ns[i];
        for (int i = 2; i * i <= n; i++){
            while (n % i == 0){
                factor[i]++;
                n /= i;
            }
        }
        if (n != 1) factor[n]++;
    }
    return factor;
}

int solve() {
    int num = 0;
    for (int n = 23; n <= 100; n++) {
        for (int r = 1; r <= n / 2; r++) {
            vector<int> vn;
            vector<int> vd;
            for (int i = n, j = r; i >= n - r + 1; i--, j--) {
                vn.push_back(i);
                vd.push_back(j);
            }
            map<int, int> mn = primefactor(vn);
            map<int, int> md = primefactor(vd);
            map<int, int> m;
            for (map<int, int>::iterator nitr = mn.begin(); nitr != mn.end(); nitr++){
                int a = nitr->first;
                int b = nitr->second;
                int c;
                map<int, int>::iterator ditr = md.find(a);
                if (ditr == md.end()) c = 0;
                else c = ditr->second;
                m[a] = b - c;
            }
            long long product = 1;
            for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++){
                product *= (int)pow((double)itr->first, (double)itr->second); 
                if (product >= 1000000) {
                    if (n % 2 == 0 && n / 2 == r) num += 1;
                    else num += 2;
                    break;
                }
            }
        }
    }
    return num;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 4075
