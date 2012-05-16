#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve() {
    int ret = 0;
    int max = 0;
    for (int n = 2; n < 1000; ++n) {
        vector<int> numbers;    // ���̌����̃��X�g
        vector<int> numerators; // ���q�̃��X�g
        int numerator = 1;      // �ŏ��̕��q
        int start = 0;          // �z�߂̊J�n�C���f�b�N�X
        bool dividable = false; // ����؂�邩�t���O
        while (true) {
            numerators.push_back(numerator);
            int number = 0; // ���̌���
            while (true) {
                number++;
                numerator *= 10;
                if (numerator / n != 0) break;
            }
            numbers.push_back(number);
            // �]������߂āA���q���X�V
            numerator = (numerator % n);
            // ����؂�邩����
            if (numerator == 0) {
                dividable = true;
                break;
            }
            // �z�߂����邩�ǂ���
            bool find = false;
            for (int i = 0; i < numerators.size(); ++i) {
                // ���q���ȑO�̕��q�Ɠ����ɂȂ����犄��Z�̌��ʂ������ɂȂ�̂ŏz�߂ɂȂ�
                if (numerator == numerators[i]) {
                    start = i;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        // ����؂ꂽ��z�߂͎����Ȃ�
        if (dividable) continue;
        // �z�߂̌���
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
