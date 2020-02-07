// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// 解答超出时间限制
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		vector<int> a(prices.size());
		vector<int> b(prices.size());
		for (int i = 1; i < prices.size(); ++i) {
			int max = 0;
			for (int j = 0; j < i; ++j) {
				int x = prices[i] - prices[j];
				if (max < x) max = x;
			}
			a[i] = max;
		}
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			int max = 0;
			for (int j = 0; j < i; ++j) {
				int last_max = 0;
				for (int k = 0; k < j; ++k) {
					if (last_max < a[k]) last_max = a[k];
				}
				int x = last_max + (prices[i] - prices[j]);
				if (max < x) max = x;
			}
			b[i] = max;
			if (profit < max) profit = max;
		}
		return profit;
    }
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,3,5,0,0,3,1,4};
		printf("%d\n", s.maxProfit(a)); // answer: 6
	}
	{
		vector<int> a = {1,2,3,4,5};
		printf("%d\n", s.maxProfit(a)); // answer: 4
	}
	{
		vector<int> a = {7,6,4,3,1};
		printf("%d\n", s.maxProfit(a)); // answer: 0
	}
	{
		vector<int> a = {1,2,4,2,5,7,2,4,9,0};
		printf("%d\n", s.maxProfit(a)); // answer: 13
	}
	{
		vector<int> a = {3,2,6,5,0,3};
		printf("%d\n", s.maxProfit(a)); // answer: 7
	}
	return 0;
}
