// https://leetcode-cn.com/problems/missing-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		n = n * (n + 1) / 2;
		for (auto x : nums) {
			n -= x;
		}
		return n;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,0,1};
		cout << s.missingNumber(a) << endl; // answer: 2
	}
	{
		vector<int> a = {9,6,4,2,3,5,7,0,1};
		cout << s.missingNumber(a) << endl; // answer: 8
	}
	return 0;
}
