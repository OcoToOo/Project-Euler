#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 80

int matrix[N][N];
int dp[2][N];

void read() {
    FILE* fp = fopen("matrix.txt", "r");
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            fscanf(fp, "%d", &(matrix[i][j]));
        }
    }
    fclose(fp);
    return ;
}

int solve(){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (i == 0 && j== 0){
                dp[i & 1][j] = matrix[i][j];
            } else if (i == 0){
                dp[i & 1][j] = dp[i & 1][j - 1] + matrix[i][j];
            } else if (j == 0){
                dp[i & 1][j] = dp[(i - 1) & 1][j] + matrix[i][j];
            } else {
                dp[i & 1][j] = min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]) + matrix[i][j];
            }
        }
    }
    return dp[(N - 1) & 1][N - 1];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

// Answer : 427337
