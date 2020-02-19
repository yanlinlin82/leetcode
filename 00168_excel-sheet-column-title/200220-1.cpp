// https://leetcode-cn.com/problems/excel-sheet-column-title/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		for (long long e = 1, w = 1; n >= e; e *= 26, ++w) {
			n -= e;
			if (n < e * 26) {
				string s;
				for (int i = 0; i < w; ++i) {
					s = static_cast<char>('A' + (n % 26)) + s;
					n /= 26; 
				}
				return s;
			}
		}
		return "";
	}
};

int main()
{
	Solution s;
	printf("'%s'\n", s.convertToTitle(1).c_str()); // answer: "A"
	printf("'%s'\n", s.convertToTitle(28).c_str()); // answer: "AB"
	printf("'%s'\n", s.convertToTitle(701).c_str()); // answer: "ZY"
	printf("'%s'\n", s.convertToTitle(1000000001).c_str()); // answer: "ZY"
	return 0;
}
