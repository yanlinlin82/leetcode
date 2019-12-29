// https://leetcode-cn.com/problems/maximum-subarray/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		int maxSum = nums[0];
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = i; j < n; ++j) {
				sum += nums[j];
				if (sum > maxSum) {
					maxSum = sum;
				}
			}
		}
		return maxSum;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
		printf("%d\n", s.maxSubArray(a)); // answer: 6
	}
	return 0;
}
