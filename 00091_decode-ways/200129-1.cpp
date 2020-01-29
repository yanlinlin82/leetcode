// https://leetcode-cn.com/problems/decode-ways/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		if (s.size() == 1) return 1;
		vector<int> a(s.size());
		a[0] = 1;
		if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
			a[1] = (s[1] == '0' ? 1 : 2);
		} else {
			a[1] = (s[1] == '0' ? 0 : 1);
		}
		for (size_t i = 2; i < a.size(); ++i) {
			if (s[i - 1] == '0' && s[i] == '0') return 0;
			if (s[i] != '0') { a[i] = a[i - 1]; }
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) { a[i] += a[i - 2]; }
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.numDecodings("12")); // answer: 2
	printf("%d\n", s.numDecodings("226")); // answer: 3
	printf("%d\n", s.numDecodings("0")); // answer: 0
	printf("%d\n", s.numDecodings("10")); // answer: 1
	printf("%d\n", s.numDecodings("20")); // answer: 1
	printf("%d\n", s.numDecodings("30")); // answer: 0
	printf("%d\n", s.numDecodings("2020")); // answer: 1
	printf("%d\n", s.numDecodings("3030")); // answer: 0
	printf("%d\n", s.numDecodings("12307")); // answer: 0
	printf("%d\n", s.numDecodings("110")); // answer: 1
	printf("%d\n", s.numDecodings("01")); // answer: 0
	return 0;
}
