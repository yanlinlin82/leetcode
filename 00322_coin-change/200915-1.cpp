// https://leetcode-cn.com/problems/coin-change/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 0) return -1;
		if (amount == 0) return 0;
		vector<int> a(amount + 1);
		for (int i = 1; i <= amount; ++i) {
			a[i] = -1;
		}
		for (int i = 0; i <= amount; ++i) {
			if (a[i] < 0) continue;
			for (int j = 0; j < coins.size(); ++j) {
				long long k = (long long)i + coins[j];
				if (k <= amount) {
					if (a[k] < 0 || a[k] > a[i] + 1) {
						a[k] = a[i] + 1;
					}
				}
				//cout << "[" << i << ", " << j << "] ";
				//for (auto e : a) cout << e << " ";
				//cout << endl;
			}
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	{
		vector<int> coins = { 1, 2, 5 };
		cout << s.coinChange(coins, 11) << endl; // answer: 3
	}
	{
		vector<int> coins = { 2 };
		cout << s.coinChange(coins, 3) << endl; // answer: -1
	}
	return 0;
}
