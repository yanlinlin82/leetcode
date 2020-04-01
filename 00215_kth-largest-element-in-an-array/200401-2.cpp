// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// 自己实现qselect
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int i = 0, j = nums.size() - 1;
		while (i <= j) {
			int idx = partition(&nums[0], i, j);
			if ((k - 1) == idx) {
				return nums[idx];
			} else if ((k - 1) < idx) {
				j = idx - 1;
			} else {
				i = idx + 1;
			}
		}
		return 0;
	}
private:
	int partition(int* a, int l, int r) {
		if (l == r) return l;
		int pivot = a[l];
		while (l < r) {
			while (l < r && a[r] <= pivot) --r;
			a[l] = a[r];
			while (l < r && a[l] >= pivot) ++l;
			a[r] = a[l];
		}
		a[l] = pivot;
		return l;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,2,1,5,6,4};
		cout << s.findKthLargest(a, 2) << endl; // answer: 5
	}
	{
		vector<int> a = {3,2,3,1,2,4,5,5,6};
		cout << s.findKthLargest(a, 4) << endl; // answer: 4
	}
	return 0;
}

