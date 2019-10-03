// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int longest = 1;
        int start = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (i < s.size() && s[i] == s[i + 1]) {
                if (longest < 2) {
                    longest = 2;
                    start = i;
                }
                for (int j = 1; i + 1 + j < s.size() && i - j >= 0; ++j) {
                    if (s[i - j] != s[i + 1 + j]) break;
                    if ((j + 1) * 2 > longest) {
                        longest = (j + 1) * 2;
                        start = i - j;
                    }
                }
            }
            for (int j = 1; i + j < s.size() && i - j >= 0; ++j) {
                if (s[i - j] != s[i + j]) break;
                if (1 + j * 2 > longest) {
                    longest = 1 + j * 2;
                    start = i - j;
                }
            }
        }
        return s.substr(start, longest);
    }
};

int main()
{
    Solution s;
    printf("%s\n", s.longestPalindrome("babad").c_str()); // answer: "bab" (or "aba")
    printf("%s\n", s.longestPalindrome("cbbd").c_str()); // answer: "bb"
    printf("%s\n", s.longestPalindrome("abcdcbcba").c_str()); // answer: "bcdcb"
    return 0;
}
