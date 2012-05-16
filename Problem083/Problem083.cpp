#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

#define INF INT_MAX

#define N 80

int matrix[N][N];

struct edge{
    int to;
    int cost;
};

vector<edge> G[N * N];

int d[N * N];

void read() {
    FILE* fp = fopen("matrix.txt", "r");
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            fscanf(fp, "%d", &(matrix[i][j]));
        }
    }
    fclose(fp);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            int k = i * N + j;
            vector<edge>& v = G[k];
            if (i > 0){
                edge e;
                e.to = k - N;
                e.cost = matrix[i - 1][j];
                v.push_back(e);
            }
            if (i < N - 1){
                edge e;
                e.to = k + N;
                e.cost = matrix[i + 1][j];
                v.push_back(e);
            }
            if (j > 0){
                edge e;
                e.to = k - 1;
                e.cost = matrix[i][j - 1];
                v.push_back(e);
            }
            if (j < N - 1){
                edge e;
                e.to = k + 1;
                e.cost = matrix[i][j + 1];
                v.push_back(e);
            }
        }
    }

    return ;
}

int solve(){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    fill(d, d + N * N, INF);
    d[0] = matrix[0][0];
    q.push(make_pair(d[0], 0));
    while (!q.empty()){
        PII p = q.top();
        q.pop();
        int index = p.second;
        if (p.first > d[index]) continue;
        vector<edge> v = G[index];
        int num = v.size();
        for (int i = 0; i < num; ++i){
            edge e = v[i];
            if (d[e.to] > d[index] + e.cost){
                d[e.to] = d[index] + e.cost;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d[N * N - 1];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

// Answer: 425185
