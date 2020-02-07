// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int profit = 0;
		int last = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < prices[i - 1]) {
				profit += prices[i - 1] - last;
				last = prices[i];
			}
		}
		profit += prices.back() - last;
		return profit;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {7,1,5,3,6,4};
		printf("%d\n", s.maxProfit(a)); // answer: 7
	}
	{
		vector<int> a = {1,2,3,4,5};
		printf("%d\n", s.maxProfit(a)); // answer: 4
	}
	{
		vector<int> a = {7,6,4,3,1};
		printf("%d\n", s.maxProfit(a)); // answer: 0
	}
	return 0;
}
