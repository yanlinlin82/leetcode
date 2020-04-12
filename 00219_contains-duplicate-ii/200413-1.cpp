// https://leetcode-cn.com/problems/contains-duplicate-ii/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size() && j <= i + k; ++j) {
				if (nums[i] == nums[j]) return true;
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
