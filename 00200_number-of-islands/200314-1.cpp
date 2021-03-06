// https://leetcode-cn.com/problems/number-of-islands/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		if (m <= 0) return 0;
		int n = grid.front().size();
		if (n <= 0) return 0;
		int c = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					++c;
					fillIsland(grid, m, n, i, j);
				}
			}
		}
		return c;
	}
private:
	void fillIsland(vector<vector<char>>& grid, int m, int n, int i, int j) {
		list<pair<int, int>> q{{i,j}};
		while (!q.empty()) {
			i = q.front().first;
			j = q.front().second;
			q.pop_front();
			grid[i][j] = '0';
			if (i > 0     && grid[i - 1][j] == '1') q.push_back(make_pair(i - 1, j));
			if (i < m - 1 && grid[i + 1][j] == '1') q.push_back(make_pair(i + 1, j));
			if (j > 0     && grid[i][j - 1] == '1') q.push_back(make_pair(i, j - 1));
			if (j < n - 1 && grid[i][j + 1] == '1') q.push_back(make_pair(i, j + 1));
		}
	}
};

int main()
{
	Solution s;
	{
		vector<vector<char>> a = {
			{'1','1','1','1','0'},
			{'1','1','0','1','0'},
			{'1','1','0','0','0'},
			{'0','0','0','0','0'},
		};
		cout << s.numIslands(a) << endl; // answer: 1
	}
	{
		vector<vector<char>> a = {
			{'1','1','0','0','0'},
			{'1','1','0','0','0'},
			{'0','0','1','0','0'},
			{'0','0','0','1','1'},
		};
		cout << s.numIslands(a) << endl; // answer: 3
	}
	return 0;
}
