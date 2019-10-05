// https://leetcode-cn.com/problems/palindrome-number/
#include <cstdio>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        char buf[256];
        int i = 0;
        while (x > 0) {
            buf[i++] = x % 10;
            x /= 10;
        }
        for (int j = 0; j < i / 2; ++j) {
            if (buf[j] != buf[i - j - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isPalindrome(121)); // answer: 1
    printf("%d\n", s.isPalindrome(-121)); // answer: 0
    printf("%d\n", s.isPalindrome(10)); // answer: 0
    printf("%d\n", s.isPalindrome(123121321)); // answer: 1
    return 0;
}
