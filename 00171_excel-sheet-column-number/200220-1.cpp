// https://leetcode-cn.com/problems/excel-sheet-column-number/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int x = 0, t = 0;
		long long e = 1;
		for (auto c : s) {
			x = x * 26 + (c - 'A');
			t += e;
			e *= 26;
		}
		return x + t;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.titleToNumber("A")); // answer: 1
	printf("%d\n", s.titleToNumber("AB")); // answer: 28
	printf("%d\n", s.titleToNumber("ZY")); // answer: 701
	return 0;
}
