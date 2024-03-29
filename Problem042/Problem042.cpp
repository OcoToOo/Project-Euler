#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define N 1786

vector<string> v;

void read(){
    FILE* fp = fopen("words.txt", "r");
    for (int i = 0; i < N; ++i){
        char tmp[256];
        fscanf(fp, "%s", tmp);
        string s(tmp);
        v.push_back(s);
    }
}

bool isTriangle(int n) {
    int tmp1 = n << 1;
    for (int i = 1; ; ++i) {
        int tmp2 = i * i + i;
        if (tmp2 > tmp1) return false; 
        if (tmp2 == tmp1) return true;
    }
}

int solve() {
    read();
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        string& s = v[i];
        int len = s.size();
        int value = 0;
        for (int j = 0; j < len; ++j) {
            value += s[j] - 'A' + 1;
        }
        if (isTriangle(value)) ret++;
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 162
