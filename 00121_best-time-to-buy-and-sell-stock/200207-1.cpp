// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max = 0;
		for (int i = 0; i + 1 < prices.size(); ++i) {
			for (int j = i + 1; j < prices.size(); ++j) {
				int x = prices[j] - prices[i];
				if (max < x) max = x;
			}
		}
		return max;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = { 7,1,5,3,6,4 };
		printf("%d\n", s.maxProfit(a)); // answer: 5
	}
	{
		vector<int> a = { 7,6,4,3,1 };
		printf("%d\n", s.maxProfit(a)); // answer: 0
	}
	return 0;
}
