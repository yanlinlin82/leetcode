// https://leetcode-cn.com/problems/jump-game/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return true;
		int farthest = 0;
		for (int i = 0; i < n; ++i) {
			if (i > farthest) return false;
			if (i < n - 1) {
				int x = i + nums[i];
				if (x > farthest) {
					farthest = x;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,3,1,1,4};
		printf("%d\n", s.canJump(a)); // answer: true
	}
	{
		vector<int> a = {3,2,1,0,4};
		printf("%d\n", s.canJump(a)); // answer: false
	}
	{
		vector<int> a = {0,1};
		printf("%d\n", s.canJump(a)); // answer: false
	}
	return 0;
}
