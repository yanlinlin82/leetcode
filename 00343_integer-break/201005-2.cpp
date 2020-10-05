// https://leetcode-cn.com/problems/integer-break/
#include <iostream>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		return calc(n, false);
	}
private:
	int calc(int n, bool allowNoSplit = true) {
		static int results[59] = { };
		if (results[n] == 0) {
			int s = numeric_limits<int>::min();
			for (int i = 1; i <= n / 2; ++i) {
				int x = calc(i) * calc(n - i);
				if (x > s) s = x;
			}
			results[n] = s;
		}
		if (allowNoSplit) {
			return max(results[n], n);
		} else {
			return results[n];
		}
	}
};

int main()
{
	Solution s;
	cout << s.integerBreak(2) << endl; // answer: 1
	cout << s.integerBreak(10) << endl; // answer: 36
	return 0;
}
