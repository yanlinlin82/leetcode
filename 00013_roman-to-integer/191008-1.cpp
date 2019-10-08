// https://leetcode-cn.com/problems/roman-to-integer/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int r = 0;
        for (const char* p = s.c_str(); *p; ++p) {
            if (*p == 'M') {
                r += 1000;
            } else if (*p == 'D') {
                r += 500;
            } else if (*p == 'C') {
                char c = *(p + 1);
                if (c == 'D' || c == 'M') {
                    r -= 100;
                } else {
                    r += 100;
                }
            } else if (*p == 'L') {
                r += 50;
            } else if (*p == 'X') {
                char c = *(p + 1);
                if (c == 'L' || c == 'C') {
                    r -= 10;
                } else {
                    r += 10;
                }
            } else if (*p == 'V') {
                r += 5;
            } else if (*p == 'I') {
                char c = *(p + 1);
                if (c == 'V' || c == 'X') {
                    r -= 1;
                } else {
                    r += 1;
                }
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.romanToInt("III")); // answer: 3
    printf("%d\n", s.romanToInt("IV")); // answer: 4
    printf("%d\n", s.romanToInt("IX")); // answer: 9
    printf("%d\n", s.romanToInt("LVIII")); // answer: 58
    printf("%d\n", s.romanToInt("MCMXCIV")); // answer: 1994
    return 0;
}
