// https://leetcode-cn.com/problems/house-robber/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		vector<vector<int>> m(n + 1);
		m[0].resize(2);
		for (int i = 0; i < n; ++i) {
			m[i + 1].resize(2);
			m[i + 1][0] = max(m[i][0], m[i][1]);
			m[i + 1][1] = m[i][0] + nums[i];
		}
		return max(m.back()[0], m.back()[1]);
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		cout << s.rob(a) << endl; // answer: 4
	}
	{
		vector<int> a = {2,7,9,3,1};
		cout << s.rob(a) << endl; // answer: 12
	}
	return 0;
}
