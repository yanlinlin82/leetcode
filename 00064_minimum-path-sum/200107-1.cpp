// https://leetcode-cn.com/problems/minimum-path-sum/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		for (int i = 1; i < grid[0].size(); ++i) {
			grid[0][i] += grid[0][i - 1];
		}
		for (int j = 1; j < grid.size(); ++j) {
			grid[j][0] += grid[j - 1][0];
		}
		for (int j = 1; j < grid.size(); ++j) {
			for (int i = 1; i < grid[j].size(); ++i) {
				grid[j][i] += std::min(grid[j - 1][i], grid[j][i - 1]);
			}
		}
		return grid.back().back();
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{1,3,1},
			{1,5,1},
			{4,2,1}
		};
		printf("%d\n", s.minPathSum(a)); // answer: 7
	}
	return 0;
}
