#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void read(vector<int>& codes) {
    FILE* fp = fopen("cipher1.txt", "r");
    while (true) {
        char ch;
        int code = 0;
        while (true) {
            ch = fgetc(fp);
            if (ch == ',' || ch == EOF) break;
            code = 10 * code + ch - '0';
        }
        codes.push_back(code);
        if (ch == EOF) break;
    }
    fclose(fp);
    return ;
}

int solve() {
    vector<int> codes;
    read(codes);
    int keys[3];
    int max = 0;
    string original;
    for (int a = 97; a < 123; a++) {
        keys[0] = a;
        for (int b = 97; b < 123; b++) {
            keys[1] = b;
            for (int c = 97; c < 123; c++) {
                keys[2] = c;
                string canditate;
                for (int i = 0; i < codes.size(); ++i) {
                    canditate.append(1, codes[i] ^ keys[i % 3]);
                }
                int cnt = 0;
                for (int pos = 0; ; ) {
                    pos = canditate.find(" and ", pos);
                    if (pos == string::npos) break;
                    pos += 5;
                    cnt++;
                }
                for (int pos = 0; ; ) {
                    pos = canditate.find(" is ", pos); 
                    if (pos == string::npos) break;
                    pos += 4;
                    cnt++;
                }
                if (cnt > max) {
                    max = cnt;
                    original.assign(canditate);
                }
            }
        }
    }
    return accumulate(original.begin(), original.end(), 0);
}

int main(){
    cout << solve() << endl;
    return 0;
}

// Answer: 107359
