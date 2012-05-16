#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

int in[400];

void read(){
    FILE* fp = fopen("Problem011.in", "r");
    for (int i = 0; i < 400; ++i){
        fscanf(fp, "%d", &(in[i]));
    }
    fclose(fp);
}

int solve(){
    int max = 0;

    for (int row = 0; row < 20; ++row) {
        for (int sequence = 0; sequence < 20 - 3; ++sequence) {
            int product = 1;
            for (int i = 0; i < 4; ++i){
                product *= in[row * 20 + sequence + i];
            }
            if (product > max){
                max = product;
            }
        }
    }

    for (int sequence = 0; sequence < 20; ++sequence) {
        for (int row = 0; row < 20 - 3; ++row) {
            int product = 1;
            for (int i = 0; i < 4; ++i) {
                product *= in[sequence + 20 * i + row];
            }
            if (product > max) {
                max = product;
            }
        }
    }

    for (int row = 0; row < 20 - 3; ++row) {
        for (int sequence = 0; sequence < 20 - 3; ++sequence){
            int product = 1;
            for (int i = 0; i < 4; ++i) {
                product *= in[row * 20 + sequence + i * 21];
            }
            if (product > max) {
                max = product;
            }
        }
    }

    for (int row = 0; row < 20 - 3; ++row) {
        for (int sequence = 20; sequence >= 4; --sequence) {
            int product = 1;
            for (int i = 0; i < 4; ++i) {
                product *= in[row * 20 + sequence + i * 19];
            }
            if (product > max) {
                max = product;
            }
        }
    }

    return max;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}

// Answer: 70600674
