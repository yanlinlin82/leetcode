// https://leetcode-cn.com/problems/add-digits/
#include <iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		while (num >= 10) {
			int x = 0;
			while (num > 0) {
				x += num % 10;
				num /= 10;
			}
			num = x;
		}
		return num;
	}
};

int main()
{
	Solution s;
	cout << s.addDigits(38) << endl; // answer: 2
	return 0;
}
