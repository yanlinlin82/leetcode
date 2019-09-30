// https://leetcode-cn.com/problems/two-sum/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> r;
		for (size_t i = 0; i + 1 < nums.size(); ++i) {
			for (size_t j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					r.push_back(i);
					r.push_back(j);
					break;
				}
			}
		}
		return r;
	}
};

int main()
{
	vector<int> nums = {2, 7, 11, 15}; // answer: [0, 1]
	int target = 9;
	Solution s;
	vector<int> r = s.twoSum(nums, target);
	printf("[%d, %d]\n", r[0], r[1]);
	return 0;
}
