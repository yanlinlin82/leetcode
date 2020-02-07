// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// 解答错误：[1,2,4,2,5,7,2,4,9,0] => 12（正确答案13）
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		vector<int> profits;
		int last = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < prices[i - 1]) {
				profits.push_back(prices[i - 1] - last);
				last = prices[i];
			}
		}
		if (prices.back() > last) {
			profits.push_back(prices.back() - last);
		}
		if (profits.empty()) return 0;
		if (profits.size() == 1) return profits[0];
		if (profits.size() > 2) {
			sort(profits.begin(), profits.end(), greater<int>());
		}
		return profits[0] + profits[1];
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
	return 0;
}
