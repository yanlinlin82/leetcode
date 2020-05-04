// https://leetcode-cn.com/problems/power-of-two/
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		while (n > 1) {
			if (n % 2 != 0) return false;
			n /= 2;
		}
		return (n == 1);
	}
};

int main()
{
	Solution s;
	cout << s.isPowerOfTwo(1) << endl; // answer: true
	cout << s.isPowerOfTwo(16) << endl; // answer: true
	cout << s.isPowerOfTwo(218) << endl; // answer: false
	return 0;
}
