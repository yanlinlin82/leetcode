// https://leetcode-cn.com/problems/nim-game/
#include <iostream>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		if (n < 4) return true;
		if (n == 4) return false;
		return canWinNim(n % 4);
	}
};

int main() {
	Solution s;
	cout << s.canWinNim(4) << endl; // answer: 4
	return 0;
}
