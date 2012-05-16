#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define N 5163

string names[N];

void read() {
    FILE* fp = fopen("names.txt", "r");
    for (int i = 0; i < N; ++i){
        char name[256];
        fscanf(fp, "%s", name);
        string s(name);
        names[i] = s;
    }
}

int solve() {
    int sum = 0;
    sort(names, names + N);
    for (int i = 0; i < N; ++i) {
        string name = names[i];
        int len = name.size();
        int value = 0;
        for (int j = 0; j < len; ++j) {
            value += name[j] - 'A' + 1;
        }
        sum += (i + 1) * value;
    }
    return sum;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

// Answer: 871198282
