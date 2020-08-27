// https://leetcode-cn.com/problems/bulb-switcher/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		vector<bool> bulb(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = i - 1; j < n; j += i) {
				bulb[j] = !bulb[j];
			}
		}
		int c = 0;
		for (auto e : bulb) {
			if (e) ++c;
		}
		return c;
	}
};

int main()
{
	Solution s;
	cout << s.bulbSwitch(3) << endl; // answer: 1
	cout << s.bulbSwitch(9999999) << endl;
	return 0;
}
