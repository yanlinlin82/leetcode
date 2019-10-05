// https://leetcode-cn.com/problems/string-to-integer-atoi/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	const int MAX_VAL = 0x7FFFFFFF / 10;
	const int MAX_DIGIT = 0x7FFFFFFF % 10;
	int myAtoi(string str) {
		bool negative = false;
		unsigned int r = 0;
		const char* p = str.c_str();
		while (*p == ' ' || *p == '\t') {
			++p;
		}
		if (*p == '-') {
			negative = true;
			++p;
		} else if (*p == '+') {
			++p;
		}
		if (*p < '0' || *p > '9') {
			return 0;
		}
		for (; *p >= '0' && *p <= '9'; ++p) {
			int d = *p - '0';
			if ((r > MAX_VAL) || ((r == MAX_VAL) && (d > MAX_DIGIT + negative))) {
				return (negative ? -0x80000000 : 0x7FFFFFFF);
			}
			r = 10 * r + d;
		}
		return (int)(negative ? ~(r - 1) : r);
	}
};

int main() {
	Solution s;
	printf("%d\n", s.myAtoi("42")); // answer: 42
	printf("%d\n", s.myAtoi("   -42")); // answer: -42
	printf("%d\n", s.myAtoi("4193 with words")); // answer: 4193
	printf("%d\n", s.myAtoi("words and 987")); // answer: 987
	printf("%d\n", s.myAtoi("-91283472332")); // answer: -2147483648
	printf("%d\n", s.myAtoi("-2147483648")); // answer: -2147483648
	return 0;
}
