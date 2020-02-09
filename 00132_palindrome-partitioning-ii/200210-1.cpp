// https://leetcode-cn.com/problems/palindrome-partitioning-ii/
// 挑战失败，超出时间限制
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int min = -1;
		minCut(s.c_str(), s.size(), 0, min);
		return (min <= 1 ? 0 : min - 1);
	}
private:
	void minCut(const char* s, int n, int p, int& min) {
		if (n <= 0) {
			if (min == -1 || p < min) {
				min = p;
			}
		} else {
			for (int i = n; i >= 1; --i) {
				if (is_palindrome(s, i) && (min == -1 || p + 1 < min)) {
					minCut(s + i, n - i, p + 1, min);
				}
			}
		}
	}
	bool is_palindrome(const char* s, int n) {
		if (n <= 1) return true;
		const char* t = s + n - 1;
		while (s < t) {
			if (*s++ != *t--) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.minCut("aab")); // answer: 1
	printf("%d\n", s.minCut("")); // answer: 0
	printf("%d\n", s.minCut("a")); // answer: 0
	printf("%d\n", s.minCut("aa")); // answer: 0
	printf("%d\n", s.minCut("abaca")); // answer: 2
	return 0;
}
