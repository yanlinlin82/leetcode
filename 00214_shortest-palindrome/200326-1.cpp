// https://leetcode-cn.com/problems/shortest-palindrome/
// 挑战失败：超出时间限制
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		//cout << "s = '" << s << "'" << endl;
		int n = s.size();
		for (; n > 1; --n) {
			int i = n / 2 - 1;
			int j = i + 1 + (n % 2);
			//cout << "n = " << n << ", i = " << i << ", j = " << j << endl;
			for (; i >= 0; --i, ++j) {
				if (s[i] != s[j]) break;
			}
			if (i < 0) break;
		}
		//cout << "n = " << n << endl;
		string t;
		for (int i = n; i < s.size(); ++i) {
			t = s[i] + t;
		}
		return t + s;
	}
};

int main()
{
	Solution s;
	cout << s.shortestPalindrome("aacecaaa") << endl; // answer: aaacecaaa
	cout << s.shortestPalindrome("abcd") << endl; // answer: dcbabcd
	cout << s.shortestPalindrome("abbacd") << endl; // answer: dcabbacd
	return 0;
}
