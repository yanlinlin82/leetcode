// https://leetcode-cn.com/problems/increasing-triplet-subsequence/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) return false;
		int a = numeric_limits<int>::max(); // record min
		int b = numeric_limits<int>::max(); // record min with previous small
		for (auto e : nums) {
			if (e < a) a = e;
			if (e > a && e < b) b = e;
			if (e > b) return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<int> nums = {1,2,3,4,5};
		cout << s.increasingTriplet(nums) << endl; // answer: true
	}
	{
		vector<int> nums = {5,4,3,2,1};
		cout << s.increasingTriplet(nums) << endl; // answer: false
	}
	{
		vector<int> nums = {1,5,4,3,2};
		cout << s.increasingTriplet(nums) << endl; // answer: false
	}
	{
		vector<int> nums = {5,3,4,1,2};
		cout << s.increasingTriplet(nums) << endl; // answer: false
	}
	return 0;
}
