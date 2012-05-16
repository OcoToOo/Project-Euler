#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

int digits[1000];

void read() {
    FILE* fp = fopen("Problem008.txt", "r");
    int p = 0;
    while (true) {
        char ch = fgetc(fp);
        if (ch == '\n') continue;
        if (ch == EOF) break;
        digits[p++] = ch  - '0';
    }
    fclose(fp);
}

// syakutori
int solve(){
    int answer = 0;
    int s = 0;
    int t = 0;
    int product = 1;
    for ( ; s < 1000 - 4; ) {
        for ( ; t < s + 5; ++t){
            product *= digits[t];
            if (product == 0) break;
        }
        answer = max(answer, product);
        if (product == 0){
            product = 1;
            s = t + 5;
            t += 5;
        } else {
            product /= digits[s];
            s++;
        }
    }
    return answer;
}

int main(){
    read();
    cout << solve() << endl;
    return 0;
}

// Answer: 40824
