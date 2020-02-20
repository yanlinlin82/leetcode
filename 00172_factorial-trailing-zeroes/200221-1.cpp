// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
// 挑战失败，超出时间限制
#include <iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int two = 0, five = 0;
		for (int i = 2; i <= n; ++i) {
			int x = i;
			while (x % 2 == 0) { ++two; x /= 2; }
			while (x % 5 == 0) { ++five; x /= 5; }
		}
		return (two <= five ? two : five);
	}
};

int main()
{
	Solution s;
	cout << s.trailingZeroes(3) << endl; // answer: 0, 3! = 6
	cout << s.trailingZeroes(5) << endl; // answer: 1, 5! = 120
	cout << s.trailingZeroes(10) << endl; // answer: 2, 10! = 3628800
	cout << s.trailingZeroes(15) << endl; // answer: 3, 15! = 1307674368000
	cout << s.trailingZeroes(20) << endl; // answer: 4, 20! = 2432902008176640000
	return 0;
}
