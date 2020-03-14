// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
#include <iostream>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		unsigned int a = 1;
		unsigned int res = 0;
		for (int i = 0; i < 32; ++i) {
			bool flag = ((m & a) != 0);
			if (flag) {
				unsigned int next = (m & ~(a - 1)) + a;
				if (next <= n) {
					flag = false;
				}
			}
			if (flag) {
				res |= a;
			}
			a <<= 1;
		}
		return (int)res;
	}
};

int main()
{
	Solution s;
	cout << s.rangeBitwiseAnd(5, 7) << endl; // answer: 4
	cout << s.rangeBitwiseAnd(0, 1) << endl; // answer: 0
	cout << s.rangeBitwiseAnd(0, 2147483647) << endl; // answer: 0
	cout << s.rangeBitwiseAnd(2147483647, 2147483647) << endl; // answer: 2147483647
	cout << s.rangeBitwiseAnd(2147483646, 2147483647) << endl; // answer: 2147483646
	return 0;
}
