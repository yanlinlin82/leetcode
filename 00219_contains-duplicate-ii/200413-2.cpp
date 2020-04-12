// https://leetcode-cn.com/problems/contains-duplicate-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> a;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > k) --a[nums[i - k - 1]];
			if (a[nums[i]] > 0) return true;
			++a[nums[i]];
		}
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		cout << s.containsNearbyDuplicate(a, 3) << endl; // answer: true
	}
	{
		vector<int> a = {1,0,1,1};
		cout << s.containsNearbyDuplicate(a, 1) << endl; // answer: true
	}
	{
		vector<int> a = {1,2,3,1,2,3};
		cout << s.containsNearbyDuplicate(a, 2) << endl; // answer: false
	}
	return 0;
}
