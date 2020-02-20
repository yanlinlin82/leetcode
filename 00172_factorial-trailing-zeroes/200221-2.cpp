// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
#include <iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int five = 0;
		while (n >= 5) {
			n /= 5;
			five += n;
		}
		return five;
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
	cout << s.trailingZeroes(1808548329) << endl; // answer:
	return 0;
}
