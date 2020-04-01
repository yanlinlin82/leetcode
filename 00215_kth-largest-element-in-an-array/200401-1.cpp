// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// 使用STL函数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k - 1];
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
