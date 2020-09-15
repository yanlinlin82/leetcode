// https://leetcode-cn.com/problems/power-of-three/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
		while (n >= 3) {
			if (n % 3 != 0) return false;
			n /= 3;
		}
		return (n == 1);
    }
};

int main()
{
	Solution s;
	cout << s.isPowerOfThree(27) << endl; // answer: true
	cout << s.isPowerOfThree(0) << endl; // answer: false
	cout << s.isPowerOfThree(9) << endl; // answer: true
	cout << s.isPowerOfThree(45) << endl; // answer: false
	return 0;
}
