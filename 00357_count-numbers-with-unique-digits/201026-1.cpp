// https://leetcode-cn.com/problems/count-numbers-with-unique-digits/
#include <iostream>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 10;
		if (n == 2) return 
	}
};

int main()
{
	Solution s;
	cout << s.countNumbersWithUniqueDigits(2) << endl; // answer: 91
	return 0;
}
