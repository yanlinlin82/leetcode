// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return vector<int>{-1, -1};
		return foundBoundary(&nums[0], 0, nums.size() - 1, target);
	}
private:
	vector<int> foundBoundary(const int* a, int i, int j, int target) {
		if (i > j) {
			return vector<int>{-1, -1};
		}
		if (a[i] == target && a[j] == target) {
			return vector<int>{i, j};
		}
		if (a[i] == target) {
			int k = foundUpperBoundary(a, i, j, target);
			return vector<int>{i, k};
		}
		if (a[j] == target) {
			int k = foundLowerBoundary(a, i, j, target);
			return vector<int>{k, j};
		}
		int k = (i + j) / 2;
		if (a[k] == target) {
			i = foundLowerBoundary(a, i, k, target);
			j = foundUpperBoundary(a, k, j, target);
			return vector<int>{i, j};
		} else if (a[k] > target) {
			return foundBoundary(a, i + 1, k - 1, target);
		} else {
			return foundBoundary(a, k + 1, j - 1, target);
		}
	}
	int foundLowerBoundary(const int* a, int i, int j, int target) {
		int k = (i + j) / 2;
		if (a[k] == target) {
			if (k - 1 <= i || a[k - 1] < target) {
				return k;
			}
			return foundLowerBoundary(a, i, k, target);
		} else {
			if (a[k + 1] == target) {
				return k + 1;
			}
			return foundLowerBoundary(a, k, j, target);
		}
	}
	int foundUpperBoundary(const int* a, int i, int j, int target) {
		int k = (i + j) / 2;
		if (a[k] == target) {
			if (k + 1 >= j || a[k + 1] > target) {
				return k;
			}
			return foundUpperBoundary(a, k, j, target);
		} else {
			if (a[k - 1] == target) {
				return k - 1;
			}
			return foundUpperBoundary(a, i, k, target);
		}
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {5,7,7,8,8,10};
		auto b = s.searchRange(a, 8);
		printf("%d,%d\n", b[0], b[1]); // answer: 3, 4
	}
	{
		vector<int> a = {5,7,7,8,8,10};
		auto b = s.searchRange(a, 6);
		printf("%d,%d\n", b[0], b[1]); // answer: -1, -1
	}
	{
		vector<int> a = {};
		auto b = s.searchRange(a, 6);
		printf("%d,%d\n", b[0], b[1]); // answer: -1, -1
	}
	{
		vector<int> a = {6};
		auto b = s.searchRange(a, 6);
		printf("%d,%d\n", b[0], b[1]); // answer: 0, 0
	}
	{
		vector<int> a = {1,1,2};
		auto b = s.searchRange(a, 1);
		printf("%d,%d\n", b[0], b[1]); // answer: 0, 1
	}
	return 0;
}
