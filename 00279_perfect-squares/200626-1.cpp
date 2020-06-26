// https://leetcode-cn.com/problems/perfect-squares/
// 调整失败，超出时间限制
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		return numSquares(n, (int)sqrt(n));
	}
private:
	int numSquares(int n, int x) {
		int res = 0;
		for (int i = x; i >= 1; --i) {
			int rest = n - i * i;
			if (rest == 0) return 1;
			int m = min(i, (int)sqrt(rest));
			if (res > 0 && rest / (m * m) + 1 >= res) continue;
			int r = numSquares(rest, m);
			if (r > 0) {
				if (res == 0 || (1 + r < res)) {
					res = 1 + r;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.numSquares(12) << endl; // answer: 3
	cout << s.numSquares(13) << endl; // answer: 2
	cout << s.numSquares(7168) << endl; // answer:
	return 0;
}
