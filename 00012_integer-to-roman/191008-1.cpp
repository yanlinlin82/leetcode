// https://leetcode-cn.com/problems/integer-to-roman/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const char* ROMAN[][10] = {
            /* 0 */ { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
            /* 1 */ { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
            /* 2 */ { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
            /* 3 */ { "", "M", "MM", "MMM" }
        };
        string r = ROMAN[3][num / 1000]; num %= 1000;
        r += ROMAN[2][num / 100]; num %= 100;
        r += ROMAN[1][num / 10]; num %= 10;
        r += ROMAN[0][num];
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.intToRoman(3).c_str()); // answer: "III"
    printf("%s\n", s.intToRoman(4).c_str()); // answer: "IV"
    printf("%s\n", s.intToRoman(9).c_str()); // answer: "IX"
    printf("%s\n", s.intToRoman(58).c_str()); // answer: "LVIII", L = 50, V = 5, III = 3
    printf("%s\n", s.intToRoman(1994).c_str()); // answer: "MCMXCIV", M = 1000, CM = 900, XC = 90, IV = 4
    return 0;
}
