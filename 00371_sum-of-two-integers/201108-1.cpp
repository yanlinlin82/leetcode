// https://leetcode-cn.com/problems/sum-of-two-integers/
#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		while (b != 0) {
			int sum = a ^ b;
			b = (unsigned int)(a & b) << 1;
			a = sum;
		}
		return a;
	}
};

int main()
{
	Solution s;
	cout << s.getSum(1, 2) << endl; // answer: 3
	cout << s.getSum(-2, 3) << endl; // answer: 1
	return 0;
}
