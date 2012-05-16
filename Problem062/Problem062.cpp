#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

typedef long long LL;

map<LL, LL> cubes;
map<LL, int> nums;

void caluc_cube() {
    LL minimum = (LL)pow(10.0, (double)(12 - 1));
    LL maximum = (LL)pow(10.0, (double)(12)) - 1;
    for (LL i = 0; ; ++i) {
        LL cube = i * i * i;
        if (cube < minimum) continue;
        if (cube > maximum) break;
        vector<int> digits;
        LL number = cube;
        while (number) {
            digits.push_back(number % 10);
            number /= 10;
        }
        sort(digits.begin(), digits.end());
        number = 0;
        int size = digits.size();
        for (int j = 0; j < size; j++) {
            number = number * 10 + digits[j];
        }
        nums[number]++;
        cubes.insert(pair<LL, LL>(number, cube));
    }
}

LL solve() {
    caluc_cube();
    LL answer = LLONG_MAX;
    for (map<LL, int>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
        if (itr->second != 5) continue;
        answer = min(answer, cubes.find(itr->first)->second);
    }
    return answer;
}

int main(){
    cout << solve() << endl;
    return 0;
}

// Answer: 127035954683
