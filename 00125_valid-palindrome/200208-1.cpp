// https://leetcode-cn.com/problems/valid-palindrome/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int n = s.size();
		if (n > 0) {
			const char* p = s.c_str();
			const char* q = p + n - 1;
			while (p < q) {
				char a = *p;
				if (a >= 'a' && a <= 'z') a -= ('a' - 'A');
				if (!((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z'))) { ++p; continue; }
				char b = *q;
				if (b >= 'a' && b <= 'z') b -= ('a' - 'A');
				if (!((b >= '0' && b <= '9') || (b >= 'A' && b <= 'Z'))) { --q; continue; }
				if (a != b) return false;
				++p; --q;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isPalindrome("A man, a plan, a canal: Panama")); // answer: true
	printf("%d\n", s.isPalindrome("race a car")); // answer: false
	return 0;
}
