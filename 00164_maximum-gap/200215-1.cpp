// https://leetcode-cn.com/problems/maximum-gap/
// 传统排序，时间复杂度O(n)，空间复杂度O(1)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		sort(nums.begin(), nums.end());
		int maxGap = nums[1] - nums[0];
		for (int i = 2; i < nums.size(); ++i) {
			int gap = nums[i] - nums[i - 1];
			if (maxGap < gap) maxGap = gap;
		}
		return maxGap;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,6,9,1};
		printf("%d\n", s.maximumGap(a)); // answer: 3, between 3 and 6, or 6 and 9
	}
	{
		vector<int> a = {10};
		printf("%d\n", s.maximumGap(a)); // answer: 0, vector size < 2
	}
	{
		vector<int> a = {1,3,2,6};
		printf("%d\n", s.maximumGap(a)); // answer: 3, between 3 and 6
	}
	return 0;
}
