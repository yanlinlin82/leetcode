// https://leetcode-cn.com/problems/valid-perfect-square/
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 0) return false;
		if (num == 0 || num == 1) return true;
		for (unsigned int i = 2; i * i <= num; ++i) {
			if (i * i == num) return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.isPerfectSquare(16) << endl; // answer: true
	cout << s.isPerfectSquare(14) << endl; // answer: false
	return 0;
}
