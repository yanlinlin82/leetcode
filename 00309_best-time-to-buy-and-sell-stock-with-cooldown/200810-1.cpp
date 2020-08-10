// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//
// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 示例:
//
// 输入: [1,2,3,0,2]
// 输出: 3
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size();
		vector<vector<int>> m(3); // m[0] => 买入, m[1] => 卖出, m[2] => 冷冻期
		for (int i = 0; i < 3; ++i) {
			m[i].resize(n);
		}
		m[0][0] = -prices[0];
		for (int i = 1; i < n; ++i) {
			m[0][i] = max(m[0][i - 1], m[2][i - 1] - prices[i]);
			m[1][i] = max(m[1][i - 1], m[0][i - 1] + prices[i]);
			m[2][i] = max(m[2][i - 1], m[1][i - 1]);
		}
#if 0
		for (auto e : prices) cout << e << " "; cout << endl;
		for (auto r : m) {
			for (auto e : r) cout << e << " "; cout << endl;
		}
#endif
		return max(m[0].back(), max(m[1].back(), m[2].back()));
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,0,2};
		cout << s.maxProfit(a) << endl; // answer: 3
	}
	return 0;
}
