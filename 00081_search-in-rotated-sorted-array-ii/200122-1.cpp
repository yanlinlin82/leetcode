// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		return searchRotated(nums, 0, nums.size() - 1, target);
	}
private:
	bool searchRotated(vector<int>& nums, int i, int j, int target) {
		if (i > j || i >= nums.size() || j < 0) return false;
		int k = (i + j) / 2;
		if (nums[k] == target) return true;
		if (nums[i] < nums[k]) {
			if (searchOrdered(nums, i, k - 1, target)) return true;
			if (searchRotated(nums, k + 1, j, target)) return true;
		} else if (nums[k] < nums[j]) {
			if (searchRotated(nums, i, k - 1, target)) return true;
			if (searchOrdered(nums, k + 1, j, target)) return true;
		} else {
			if (searchRotated(nums, i, k - 1, target)) return true;
			if (searchRotated(nums, k + 1, j, target)) return true;
		}
		return false;
	}
	bool searchOrdered(vector<int>& nums, int i, int j, int target) {
		if (i > j || i >= nums.size() || j < 0) return false;
		int k = (i + j) / 2;
		if (nums[k] == target) return true;
		if (nums[k] < target) {
			return searchOrdered(nums, k + 1, j, target);
		} else {
			return searchOrdered(nums, i, k - 1, target);
		}
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,5,6,0,0,1,2};
		printf("%d\n", s.search(a, 0)); // answer: true
	}
	{
		vector<int> a = {2,5,6,0,0,1,2};
		printf("%d\n", s.search(a, 3)); // answer: false
	}
	return 0;
}
