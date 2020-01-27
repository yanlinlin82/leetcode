// https://leetcode-cn.com/problems/scramble-string/
// 第四次尝试：挑战失败，超出时间限制
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		//printf("'%s', '%s'\n", s1.c_str(), s2.c_str());
		int n = s1.size(), n2 = s2.size();
		if (n != n2) return false;
		if (n == 1) return (s1 == s2);
		for (int i = 1; i < n; ++i) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
					isScramble(s1.substr(i), s2.substr(i))) {
				return true;
			}
			if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
					isScramble(s1.substr(i), s2.substr(0, n - i))) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isScramble("great", "rgeat")); // answer: true
	printf("%d\n", s.isScramble("abcde", "caebd")); // answer: false
	printf("%d\n", s.isScramble("ab", "ab")); // answer: true
	printf("%d\n", s.isScramble("ab", "ba")); // answer: true
	printf("%d\n", s.isScramble("abc", "abc")); // answer: true
	printf("%d\n", s.isScramble("abc", "cba")); // answer: true
	printf("%d\n", s.isScramble("abc", "bca")); // answer: true
	printf("%d\n", s.isScramble("abc", "acb")); // answer: true
	printf("%d\n", s.isScramble("abc", "bac")); // answer: true
	printf("%d\n", s.isScramble("abc", "cab")); // answer: true
	printf("%d\n", s.isScramble("a", "b")); // answer: false
	printf("%d\n", s.isScramble("ab", "aa")); // answer: false
	printf("%d\n", s.isScramble("aa", "aa")); // answer: true
	printf("%d\n", s.isScramble("abb", "bab")); // answer: true
	printf("%d\n", s.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb")); // answer: true
	return 0;
}
