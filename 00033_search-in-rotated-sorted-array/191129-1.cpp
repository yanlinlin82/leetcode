// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		return search(&nums[0], 0, nums.size() - 1, target);
	}
private:
	int search(const int* a, int i, int j, int target) {
		if (i == j) {
			return (a[i] == target ? i : -1);
		}
		if (a[i] == target) return i;
		if (a[j] == target) return j;
		if (i + 1 == j) return -1;
		if (a[i] < a[j]) {
			if (target < a[i] || target > a[j]) return -1;
		} else {
			if (target < a[i] && target > a[j]) return -1;
		}
		int k = (i + j) / 2;
		if (a[k] == target) return k;
		int n = search(a, i, k - 1, target);
		if (n >= 0) return n;
		n = search(a, k + 1, j, target);
		if (n >= 0) return n;
		return -1;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {4,5,6,7,0,1,2};
		printf("%d\n", s.search(a, 0)); // answer: 4
	}
	{
		vector<int> a = {4,5,6,7,0,1,2};
		printf("%d\n", s.search(a, 3)); // answer: -1
	}
	return 0;
}
