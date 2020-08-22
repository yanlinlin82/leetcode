// https://leetcode-cn.com/problems/burst-balloons/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		rec.resize(n + 2, vector<int>(n + 2, - 1));
		val.resize(n + 2);
		for (int i = 0; i < n; ++i) {
			val[i + 1] = nums[i];
		}
		val[0] = val[n + 1] = 1;
		return solve(0, n + 1);
	}
private:
	int solve(int i, int j) {
		if (i >= j - 1) return 0;
		if (rec[i][j] == -1) {
			for (int k = i + 1; k < j; ++k) {
				int sum = val[i] * val[k] * val[j];
				sum += solve(i, k) + solve(k, j);
				rec[i][j] = max(rec[i][j], sum);
			}
		}
		return rec[i][j];
	}
	vector<vector<int>> rec;
	vector<int> val;
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,1,5,8};
		cout << s.maxCoins(a) << endl; // answer: 167
	}
	return 0;
}
