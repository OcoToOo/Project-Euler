#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int tointeger(int n[], int s, int e){
    int ret = 0;
    for (int i = s; i <= e; i++){
        ret = ret * 10 + n[i];
    }
    return ret;
}

int solve(){
    vector<int> v;
    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        for (int i = 1; i <= 3; ++i){
            int a = tointeger(n, 0, i);
            for (int j = i + 1; j <= 4; ++j){
                int b = tointeger(n, i + 1, j);
                int c = tointeger(n, j + 1, 8);
                int d = a * b;
                if (d > c) break;
                if (c == d) v.push_back(c);
            }
        }
    } while (next_permutation(n, n + 9));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return accumulate(v.begin(), v.end(), 0);
}

int main(){
    cout << solve() << endl;
    return 0;
}

// Answer: 45228
