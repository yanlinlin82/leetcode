// https://leetcode-cn.com/problems/dungeon-game/
// 挑战失败：解答错误（见第二组数据）
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		int n = dungeon.front().size();
		vector<vector<pair<int,int>>> a(m); // m * n * (init, curr)
		for (int i = 0; i < m; ++i) a[i].resize(n);
		if (dungeon[0][0] >= 0) {
			a[0][0].first = 1;
			a[0][0].second = dungeon[0][0] + 1;
		} else {
			a[0][0].first = 1 - dungeon[0][0];
			a[0][0].second = 1;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) continue;
				int s = (j == 0 ? numeric_limits<int>::min() : a[i][j - 1].second + dungeon[i][j]);
				int t = (i == 0 ? numeric_limits<int>::min() : a[i - 1][j].second + dungeon[i][j]);
				int s2 = (j == 0 ? numeric_limits<int>::max() : a[i][j - 1].first + (s > 0 ? 0 : (1 - s)));
				int t2 = (i == 0 ? numeric_limits<int>::max() : a[i - 1][j].first + (t > 0 ? 0 : (1 - t)));
				if (s2 < t2) {
					a[i][j].first = s2;
					a[i][j].second = (s > 0 ? s : 1);
				} else {
					a[i][j].first = t2;
					a[i][j].second = (t > 0 ? t : 1);
				}
			}
		}
		for (auto& r : dungeon) { for (auto e : r) cout << " " << e; cout << endl; }
		for (auto& r : a) { for (auto e : r) cout << " (" << e.first << "," << e.second << ")"; cout << endl; }
		return a.back().back().first;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{-2,-3,3},
			{-5,-10,1},
			{10,30,-5}
		};
		cout << s.calculateMinimumHP(a) << endl; // answer: 7
	}
	{
		vector<vector<int>> a = {
			{1,-3,3},
			{0,-2,0},
			{-3,-3,-3}
		};
		cout << s.calculateMinimumHP(a) << endl; // answer: 3
	}
	return 0;
}
