#include <vector>
#include <iostream>

using namespace std;

int digits[100][50];

void read() {
    FILE* fp = fopen("Problem013.txt", "r");
    int row = 0;
    char ch = 0;
    while (ch != EOF){
        int col = 0;
        while (true){
            ch = fgetc(fp);
            if (ch == '\n' || ch == EOF) break;
            digits[row][col] = ch - '0';
            col++;
        }
        row++;
    }
    fclose(fp);
    return ;
}

vector<int> solve(){
    vector<int> v;
    int carry = 0;
    for (int i = 49; i >= 0; --i){
        int sum = carry;
        for (int j = 0; j < 100; ++j){
            sum += digits[j][i];
        }
        v.push_back(sum % 10);
        carry = sum / 10;
    }
    while (carry){
        v.push_back(carry % 10);
        carry /= 10;
    }
    return v;
}

int main() {
    read();
    const vector<int>& v = solve();
    int size = v.size();
    for (int i = size - 1; i > size - 1 - 10; --i){
        cout << v[i];
    }
    cout << endl;
    return 0;
}

// Answer: 5537376230
