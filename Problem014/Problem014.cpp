#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool b[100 * 10000];

int solve(){
    fill(b, b + 100 * 10000, false);
    int max = 0;
    int ret = 0;
    for (int i = 999999; i >= 2; --i){
        if (b[i]) continue;
        int length = 1;
        ll value = i;
        while (true){
            value = ((value & 1) ? (value * 3 + 1) : (value / 2));
            length++;
            if (value == 1) break;
            if (value < 100 * 10000) b[value] = true;
        }
        if (length > max){
            max = length;
            ret = i;
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 837799
