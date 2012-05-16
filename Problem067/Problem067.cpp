#include <iostream>

using namespace std;

int value[100][100];

int dp[2][100];

void read() {
    FILE* fp = fopen("Problem067.txt", "r");
    for (int i = 0; i < 100; ++i){
        for (int j = 0; j <= i; ++j){
            fscanf(fp, "%d", &(value[i][j]));
        }
    }
    fclose(fp);
    return ;
}

int solve(){
    dp[0][0] = value[0][0];
    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i & 1][j] = dp[(i - 1) & 1][j] + value[i][j];
            } else if (j == i) {
                dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + value[i][j];
            } else {
                dp[i & 1][j] = max(dp[(i - 1) & 1][j - 1], dp[(i - 1) & 1][j]) + value[i][j];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 100; ++i) {
        ret = max(ret, dp[(100 - 1) & 1][i]);
    }
    return ret;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
