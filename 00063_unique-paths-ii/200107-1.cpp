// https://leetcode-cn.com/problems/unique-paths-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m <= 0) return 1;
		int n = obstacleGrid[0].size();
		if (n <= 0) return 1;
		vector<long int> a(n);
		a[0] = obstacleGrid[0][0] ? 0 : 1;
		for (int i = 1; i < n; ++i) {
			if (obstacleGrid[0][i]) break;
			a[i] = a[i - 1];
		}
		for (int j = 1; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (obstacleGrid[j][i]) {
					a[i] = 0;
				} else if (i > 0) {
					a[i] += a[i - 1];
				}
			}
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{0,0,0},
			{0,1,0},
			{0,0,0}
		};
		printf("%d\n", s.uniquePathsWithObstacles(a)); // answer: 2
	}
	{
		vector<vector<int>> a = {
			{1},
		};
		printf("%d\n", s.uniquePathsWithObstacles(a)); // answer: 0
	}
	{
		vector<vector<int>> a = {
			{0},
			{1},
		};
		printf("%d\n", s.uniquePathsWithObstacles(a)); // answer: 0
	}
	return 0;
}
