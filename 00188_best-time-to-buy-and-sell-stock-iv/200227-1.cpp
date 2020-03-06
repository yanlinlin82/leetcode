// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		return calcMaxProfit(&prices[0], prices.size(), k, 0);
	}
private:
	int calcMaxProfit(const int* a, int n, int k, int s) {
		//cout << "calcMaxProfit(n = " << n << ", k = " << k << ", s = " << s << ")"; for (int i = 0; i < n; ++i) cout << " " << a[i]; cout << endl;
		if (n <= 0 || k <= 0) return s;
		while (n > 1 && *a >= *(a+1)) { ++a; --n; }
		//cout << "start = " << *a << endl;
		int maxProfit = s;
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[0]) {
				//cout << "s = " << s << ", [" << a[0] << ", " << a[i] << "]" << endl;
				int s2 = calcMaxProfit(a + i + 1, n - i - 1, k - 1, s + a[i] - a[0]);
				if (s2 > maxProfit) maxProfit = s2;
			}
		}
		int s2 = calcMaxProfit(a + 1, n - 1, k, s);
		if (s2 > maxProfit) maxProfit = s2;
		//cout << "maxProfit = " << maxProfit << endl;
		return maxProfit;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,4,1};
		printf("%d\n", s.maxProfit(2, a)); // answer: 2
	}
	{
		vector<int> a = {3,2,6,5,0,3};
		printf("%d\n", s.maxProfit(2, a)); // answer: 7
	}
	{
		vector<int> a = {};
		printf("%d\n", s.maxProfit(2, a)); // answer: 0
	}
	{
		vector<int> a = {5,2,3,0,3,5,6,8,1,5};
		printf("%d\n", s.maxProfit(2, a)); // answer: 12
	}
	return 0;
}
