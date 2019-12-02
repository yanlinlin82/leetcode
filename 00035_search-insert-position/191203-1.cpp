// https://leetcode-cn.com/problems/search-insert-position/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		int n = nums.size();
		const int* a = &nums[0];
		if (target < a[0]) return 0;
		if (target > a[n - 1]) return n;
		int i = 0;
		int j = n - 1;
		while (i <= j) {
			if (a[i] == target) return i;
			if (a[j] == target) return j;
			int k = (i + j) / 2;
			if (k == i) return j;
			if (a[k] == target) return k;
			if (a[k] < target) {
				i = k;
			} else {
				j = k;
			}
		}
		return i;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,3,5,6};
		printf("%d\n", s.searchInsert(a, 5)); // answer: 2
	}
	{
		vector<int> a = {1,3,5,6};
		printf("%d\n", s.searchInsert(a, 2)); // answer: 1
	}
	{
		vector<int> a = {1,3,5,6};
		printf("%d\n", s.searchInsert(a, 7)); // answer: 4
	}
	{
		vector<int> a = {1,3,5,6};
		printf("%d\n", s.searchInsert(a, 0)); // answer: 0
	}
	return 0;
}
