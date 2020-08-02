// https://leetcode-cn.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = 1;
		}
		int max = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					if (a[j] + 1 > a[i]) {
						a[i] = a[j] + 1;
						if (a[i] > max) {
							max = a[i];
						}
					}
				}
			}
		}
		return max;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {10,9,2,5,3,7,101,18};
		cout << s.lengthOfLIS(a) << endl; // answer: 4
	}
	{
		vector<int> a = {2,2};
		cout << s.lengthOfLIS(a) << endl; // answer: 1
	}
	{
		vector<int> a = {1,3,6,7,9,4,10,5,6};
		cout << s.lengthOfLIS(a) << endl; // answer: 6
	}
	return 0;
}
