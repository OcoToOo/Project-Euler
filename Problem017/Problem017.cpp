#include <iostream>
#include <string>

using namespace std;

char* UNIT[] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

char* TEN_TO_NINETEEN[] = {
    "ten",
    "eleven",
    "twelve",
    "thirtenn",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

char* TENTHS[] = {
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

char* HUNDRED = "hundred";

char* THOUSAND = "onethousand";

char* AND = "and";

int LEN_OF_UNIT[9];
int LEN_OF_TEN_TO_NINETEEN[10];
int LEN_OF_TENTHS[8];
int LEN_OF_HUNDRED;
int LEN_OF_THOUSAND;
int LEN_OF_AND;

void init() {
    for (int i = 0; i < 9; i++) LEN_OF_UNIT[i] = strlen(UNIT[i]);
    for (int i = 0; i < 10; i++) LEN_OF_TEN_TO_NINETEEN[i] = strlen(TEN_TO_NINETEEN[i]);
    for (int i = 0; i < 8; i++) LEN_OF_TENTHS[i] = strlen(TENTHS[i]);
    LEN_OF_HUNDRED = strlen(HUNDRED);
    LEN_OF_THOUSAND = strlen(THOUSAND);
    LEN_OF_AND = strlen(AND);
}

int twentyToNinetyNine(int digit) {
    int num = 0;
    int quotient = digit / 10;
    num += LEN_OF_TENTHS[quotient - 2];
    int remainder = digit % 10;
    if (remainder != 0) num += LEN_OF_UNIT[remainder - 1];
    return num;
}

int oneToNinetyNine(int number) {
    int num = 0;
    if (number <= 9) {
        num = LEN_OF_UNIT[number - 1];
    } else if (10 <= number && number <= 19) {
        num = LEN_OF_TEN_TO_NINETEEN[number - 10];
    } else {
        num = twentyToNinetyNine(number);
    }
    return num;
}

int solve() {
    init();
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (i <= 99) {
            sum += oneToNinetyNine(i);
        } else if (100 <= i && i <= 999) {
            int quotient = i / 100;
            sum += LEN_OF_UNIT[quotient - 1];
            sum += LEN_OF_HUNDRED;
            int remainder = i % 100;
            if (remainder == 0) continue;
            sum += LEN_OF_AND;
            sum += oneToNinetyNine(remainder);
        } else {
            sum += LEN_OF_THOUSAND;
        }
    }
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// Answer: 21124
