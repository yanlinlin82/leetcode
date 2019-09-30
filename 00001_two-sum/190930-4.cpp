// https://leetcode-cn.com/problems/two-sum/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hash.find(nums[i]);
			if (it != hash.end()) {
				return vector<int>{it->second, i};
			}
			hash[target - nums[i]] = i;
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
