// https://leetcode-cn.com/problems/contains-duplicate-iii/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		unordered_map<int, int> a;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > k) {
				for (int j = -t; j <= t; ++j) {
					--a[nums[i - k - 1] + j];
				}
			}
			if (a[nums[i]] > 0) return true;
			for (int j = -t; j <= t; ++j) {
				++a[nums[i] + j];
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		cout << s.containsNearbyAlmostDuplicate(a, 3, 0) << endl; // answer: true
	}
	{
		vector<int> a = {1,0,1,1};
		cout << s.containsNearbyAlmostDuplicate(a, 1, 2) << endl; // answer: true
	}
	{
		vector<int> a = {1,5,9,1,5,9};
		cout << s.containsNearbyAlmostDuplicate(a, 2, 3) << endl; // answer: false
	}
	{
		vector<int> a = {0,2147483647};
		cout << s.containsNearbyAlmostDuplicate(a, 1, 2147483647) << endl; // answer: true
	}
	return 0;
}
