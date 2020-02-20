// https://leetcode-cn.com/problems/dungeon-game/
// 挑战失败，超出时间限制
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		int n = dungeon.front().size();
		vector<vector<unordered_map<int,int>>> a(m); // m * n * (init, curr)
		for (int i = 0; i < m; ++i) a[i].resize(n);
		if (dungeon[0][0] >= 0) {
			a[0][0].insert(make_pair(1, dungeon[0][0] + 1));
		} else {
			a[0][0].insert(make_pair(1 - dungeon[0][0], 1));
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) continue;
				if (j > 0) {
					for (auto it = a[i][j - 1].begin(); it != a[i][j - 1].end(); ++it) {
						add(a[i][j], it->first, it->second, dungeon[i][j]);
					}
				}
				if (i > 0) {
					for (auto it = a[i - 1][j].begin(); it != a[i - 1][j].end(); ++it) {
						add(a[i][j], it->first, it->second, dungeon[i][j]);
					}
				}
			}
		}
#if 0
		for (auto& r : dungeon) { for (auto e : r) cout << " " << e; cout << endl; }
		for (auto& r : a) {
			for (auto& e : r) {
				cout << " (";
				for (auto& p : e) {
					cout << p.first << "," << p.second << "|";
				}
				cout << ")";
			}
			cout << endl;
		}
#endif
		int init = numeric_limits<int>::max();
		for (auto it = a.back().back().begin(); it != a.back().back().end(); ++it) {
			if (it->first < init) init = it->first;
		}
		return init;
	}
private:
	void add(unordered_map<int,int>& e, int init, int curr, int delta) {
		if (curr + delta > 0) {
			curr += delta;
		} else {
			init += 1 - (curr + delta);
			curr = 1;
		}
		auto it = e.find(init);
		if (it == e.end()) {
			e.insert(make_pair(init, curr));
		} else if (curr > it->second) {
			it->second = curr;
		}
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
	{
		vector<vector<int>> a = {
			{1,-4,5,-99},
			{2,-2,-2,-1}
		};
		cout << s.calculateMinimumHP(a) << endl; // answer: 3
	}
	return 0;
}
