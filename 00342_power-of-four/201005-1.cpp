// https://leetcode-cn.com/problems/power-of-four/
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num < 1) return false;
		while (num > 1) {
			if (num % 4 != 0) return false;
			num /= 4;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isPowerOfFour(16) << endl; // answer: true
	cout << s.isPowerOfFour(5) << endl; // answer: false
	return 0;
}
