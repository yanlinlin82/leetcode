// https://leetcode-cn.com/problems/reverse-integer/
#include <cstdio>

class Solution {
public:
    const unsigned int MAX_VAL = 0x7FFFFFFF / 10;
    const unsigned int MAX_DIGIT = 0x7FFFFFFF % 10;
    int reverse(int x) {
        if (x == 0) return 0;
        int r = 0;
        bool negative = (x < 0);
        unsigned int v = (x > 0 ? x : (~(unsigned int)x) + 1);
        while (v > 0) {
            int d = v % 10;
            if ((r > MAX_VAL) || ((r == MAX_VAL) && (d > MAX_DIGIT + negative))) {
                return 0;
            }
            r = r * 10 + d;
            v = v / 10;
        }
        return (negative ? -r : r);
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.reverse(123)); // answer: 321
    printf("%d\n", s.reverse(-123)); // answer: -321
    printf("%d\n", s.reverse(120)); // answer: 21
    printf("%d\n", s.reverse(0)); // answer: 0
    printf("%d\n", s.reverse(-2147483648)); // answer: 0
    return 0;
}
