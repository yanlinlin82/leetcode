// https://leetcode-cn.com/problems/two-sum/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int* start = &nums[0];
		int* end = start + nums.size();
		for (int* p = start; p + 1 < end; ++p) {
			for (int* q = p + 1; q < end; ++q) {
				if (*p + *q == target) {
					return vector<int>{p - start, q - start};
				}
			}
		}
		return vector<int>();
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
