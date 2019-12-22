// https://leetcode-cn.com/problems/jump-game-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		vector<int> x(n);
		for (int i = 0; i + 1 < n; ++i) {
			int m = nums[i];
			for (int j = 1; j <= m && i + j < n; ++j) {
				if (x[i + j] == 0 || x[i + j] > x[i] + 1) {
					x[i + j] = x[i] + 1;
				}
			}
		}
		return x.back();
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,3,1,1,4};
		printf("%d\n", s.jump(a)); // answer: 2
	}
	{
		vector<int> a = {2,1};
		printf("%d\n", s.jump(a)); // answer: 1
	}
	{
		vector<int> a = {1,2,1,1,1};
		printf("%d\n", s.jump(a)); // answer: 3
	}
	return 0;
}
