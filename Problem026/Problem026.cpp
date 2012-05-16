#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve() {
    int ret = 0;
    int max = 0;
    for (int n = 2; n < 1000; ++n) {
        vector<int> numbers;    // 商の桁数のリスト
        vector<int> numerators; // 分子のリスト
        int numerator = 1;      // 最初の分子
        int start = 0;          // 循環節の開始インデックス
        bool dividable = false; // 割り切れるかフラグ
        while (true) {
            numerators.push_back(numerator);
            int number = 0; // 商の桁数
            while (true) {
                number++;
                numerator *= 10;
                if (numerator / n != 0) break;
            }
            numbers.push_back(number);
            // 余りを求めて、分子を更新
            numerator = (numerator % n);
            // 割り切れるか判定
            if (numerator == 0) {
                dividable = true;
                break;
            }
            // 循環節があるかどうか
            bool find = false;
            for (int i = 0; i < numerators.size(); ++i) {
                // 分子が以前の分子と同じになったら割り算の結果も同じになるので循環節になる
                if (numerator == numerators[i]) {
                    start = i;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        // 割り切れたら循環節は持たない
        if (dividable) continue;
        // 循環節の桁数
        int sum = accumulate(numbers.begin() + start, numbers.end(), 0);
        if (sum > max) {
            max = sum;
            ret = n;
        }
    }
    return ret;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 983
