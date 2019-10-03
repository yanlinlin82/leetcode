// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
		const char* b = s.c_str();
		const char* e = b + s.size();
        int longest = 1;
        const char* start = b;
		for (const char* p = b; p + 1 < e; ++p) {
			if (*p == *(p + 1)) {
				if (longest < 2) {
					longest = 2;
					start = p;
				}
				for (const char *q1 = p - 1, *q2 = p + 2;
						q1 >= b && q2 < e && *q1 == *q2;
						--q1, ++q2) {
					int size = q2 - q1 + 1;
					if (longest < size) {
						longest = size;
						start = q1;
					}
				}
			}
			for (const char *q1 = p - 1, *q2 = p + 1;
					q1 >= b && q2 < e && *q1 == *q2;
					--q1, ++q2) {
				int size = q2 - q1 + 1;
				if (longest < size) {
					longest = size;
					start = q1;
				}
            }
        }
        return string(start, start + longest);
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
