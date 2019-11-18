// https://leetcode-cn.com/problems/implement-strstr/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int n = haystack.size();
		int m = needle.size();
		for (int i = 0; i <= n - m; ++i) {
			bool mismatch = false;
			for (int j = 0; j < m; ++j) {
				if (haystack[i + j] != needle[j]) {
					mismatch = true;
					break;
				}
			}
			if (!mismatch) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.strStr("hello", "ll")); // answer: 2
	printf("%d\n", s.strStr("aaaaa", "bba")); // answer: -1
	printf("%d\n", s.strStr("hello", "")); // answer: 0
	printf("%d\n", s.strStr("", "")); // answer: 0
	printf("%d\n", s.strStr("a", "a")); // answer: 0
	printf("%d\n", s.strStr("mississippi", "mississippi")); // answer: 0
	return 0;
}
