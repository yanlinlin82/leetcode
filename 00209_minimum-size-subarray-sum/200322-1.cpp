// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int i = 0, j = 0, sum = 0, size = 0;
		for (;;) {
			while (sum < s && j < n) {
				sum += nums[j++];
			}
			if (sum < s) break;
			if (size == 0 || (j - i) < size) {
				size = j - i;
			}
			while (sum >= s && i < j) {
				sum -= nums[i++];
				if (sum >= s) {
					if (size == 0 || (j - i) < size) {
						size = j - i;
					}
				}
			}
		}
		return size;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,3,1,2,4,3};
		cout << s.minSubArrayLen(7, a) << endl; // answer: 2, 解释：[4,3]
	}
	return 0;
}
