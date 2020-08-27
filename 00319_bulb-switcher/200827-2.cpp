// https://leetcode-cn.com/problems/bulb-switcher/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		return sqrt(n);
	}
};

int main()
{
	Solution s;
	cout << s.bulbSwitch(3) << endl; // answer: 1
	cout << s.bulbSwitch(9999999) << endl;
	return 0;
}
