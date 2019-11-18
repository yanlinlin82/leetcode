// https://leetcode-cn.com/problems/divide-two-integers/
#include <cstdio>
#include <climits>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == divisor) return 1;
		if (dividend == 0 || divisor == INT_MIN) return 0;
		int value = 0;
		if (dividend == INT_MIN) {
			if (divisor > 0) {
				value = -1;
				dividend += divisor;
			} else {
				value = 1;
				dividend -= divisor;
			}
		}
		bool minus = (dividend < 0) != (divisor < 0);
		if (dividend < 0) dividend = -dividend;
		if (divisor < 0) divisor = -divisor;
		int res = 0;
		for (int i = 31; i >= 0; --i) {
			int x = (dividend >> i);
			res = res << 1;
			if (x >= divisor) {
				++res;
				dividend -= (divisor << i);
			}
		}
		if (minus) res = -res;
		if (res == INT_MAX && value > 0) return INT_MAX;
		return res + value;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.divide(10, 3)); // answer: 3
	printf("%d\n", s.divide(7, -3)); // answer: -2
	printf("%d\n", s.divide(0, 1)); // answer: 0
	printf("%d\n", s.divide(0, -1)); // answer: 0
	printf("%d\n", s.divide(1, 1)); // answer: 1
	printf("%d\n", s.divide(1, -1)); // answer: -1
	printf("%d\n", s.divide(-1, 1)); // answer: -1
	printf("%d\n", s.divide(INT_MIN, 1)); // answer: INT_MIN
	printf("%d\n", s.divide(INT_MIN, -1)); // answer: INT_MIN
	printf("%d\n", s.divide(INT_MIN, INT_MIN)); // answer: 1
	printf("%d\n", s.divide(0, INT_MIN)); // answer: 0
	printf("%d\n", s.divide(1, INT_MIN)); // answer: INT_MIN
	printf("%d\n", s.divide(-1, INT_MIN)); // answer: INT_MIN
	return 0;
}
