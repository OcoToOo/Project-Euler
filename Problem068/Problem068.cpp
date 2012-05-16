#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define NUM 10

LL solve() {
    LL max = 0;
    vector<int> answer((NUM >> 1) * 3);
    for (int i = 0; i < 1 << NUM; ++i) {
        vector<int> bits(NUM, 0);
        int cnt = 0;
        for (int j = 0; j < NUM; ++j) {
            if (1 << j & i){
                bits[j] = 1;
                cnt++;
            }
        }
        if (cnt != NUM >> 1) continue;
        vector<int> inter(NUM >> 1);
        vector<int> exter(NUM >> 1);
        for (int i = 0, n = 1, ex = 0, in = 0; i < NUM; ++i, ++n) {
            if (bits[i]) {
                exter[ex++] = n;
            } else {
                inter[in++] = n;
            }
        }
        if (find(exter.begin(), exter.end(), 10) == exter.end()) continue;
        vector<int> tmp = inter;
        vector<int> nodes((NUM >> 1) * 3);
        do {
            do {
                int sum = exter[(NUM >> 1) - 1] + inter[(NUM >> 1) - 1] + inter[0];
                bool b = true;
                for (int i = 0; i < (NUM >> 1) - 1; ++i) {
                    if (exter[i] + inter[i] + inter[i + 1] != sum) {
                        b = false;
                        break;
                    }
                    nodes[i * 3    ] = exter[i];
                    nodes[i * 3 + 1] = inter[i];
                    nodes[i * 3 + 2] = inter[i + 1];
                }
                if (!b) continue;
                nodes[((NUM >> 1) - 1) * 3    ] = exter[(NUM >> 1) - 1];
                nodes[((NUM >> 1) - 1) * 3 + 1] = inter[(NUM >> 1) - 1];
                nodes[((NUM >> 1) - 1) * 3 + 2] = inter[0];
                LL n = 0;
                for (int i = 0; i < (NUM >> 1) * 3; ++i) {
                    int node = nodes[i];
                    if (node != 10) n = n * 10 + node % 10;
                    else n = n * 100 + 10 + node % 10;
                }
                if (n > max) {
                    max = n;
                    answer = nodes;
                }
            } while (next_permutation(inter.begin(), inter.end()));

        } while (next_permutation(exter.begin() + 1, exter.end()));
    }
    return max;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 6531031914842725
