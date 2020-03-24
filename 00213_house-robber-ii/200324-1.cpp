// https://leetcode-cn.com/problems/house-robber-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		if (n == 1) return nums[0];
		int a = rob_no_cycle(nums, 0, n - 1);
		int b = rob_no_cycle(nums, 1, n);
		return max(a, b);
	}
private:
	int rob_no_cycle(vector<int>& nums, int start, int end) {
		vector<vector<int>> m(end - start + 1);
		m[0].resize(2);
		for (int i = 0; i < end - start; ++i) {
			m[i + 1].resize(2);
			m[i + 1][0] = max(m[i][0], m[i][1]);
			m[i + 1][1] = m[i][0] + nums[start + i];
		}
		return max(m.back()[0], m.back()[1]);
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,3,2};
		cout << s.rob(a) << endl; // answer: 3
	}
	{
		vector<int> a = {1,2,3,1};
		cout << s.rob(a) << endl; // answer: 4
	}
	return 0;
}
