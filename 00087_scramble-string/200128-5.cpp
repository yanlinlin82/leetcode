// https://leetcode-cn.com/problems/scramble-string/
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
		return isScramble(s1.c_str(), s2.c_str(), n);
	}
private:
	bool isScramble(const char* s1, const char* s2, int n) {
		if (n == 1) return *s1 == *s2;
		if (n == 2) return (*s1 == *s2 && *(s1+1) == *(s2+1)) || (*s1 == *(s2+1) && *(s1+1) == *s2);
		if (!isLetterTheSame(s1, s2, n)) return false;
		for (int i = 1; i < n; ++i) {
			if (isScramble(s1, s2, i) && isScramble(s1 + i, s2 + i, n - i)) {
				return true;
			}
			if (isScramble(s1, s2 + (n - i), i) && isScramble(s1 + i, s2, n - i)) {
				return true;
			}
		}
		return false;
	}
	bool isLetterTheSame(const char* s1, const char* s2, int n) {
		int c[256] = { 0 };
		for (int i = 0; i < n; ++i) { ++c[(unsigned int)s1[i]]; }
		for (int i = 0; i < n; ++i) { if (--c[(unsigned int)s2[i]] < 0) return false; }
		return true;
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
	printf("%d\n", s.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb")); // answer: false
	printf("%d\n", s.isScramble("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba")); // answer: false
	return 0;
}
