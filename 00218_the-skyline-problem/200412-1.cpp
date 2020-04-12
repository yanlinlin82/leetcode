// https://leetcode-cn.com/problems/the-skyline-problem/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		map<int, vector<int>> a;
		for (const auto& e : buildings) {
			a[e[0]].push_back(e[2]); // left edge
			a[e[1]].push_back(-e[2]); // right edge
		}
		vector<vector<int>> res;
		map<int, int> height;
		int lastY = 0;
		for (auto it = a.begin(); it != a.end(); ++it) {
			int x = it->first;
			for (auto y : it->second) {
				if (y > 0) {
					++height[y];
				} else {
					if (--height[-y] == 0) {
						height.erase(-y);
					}
				}
			}
			int y = 0;
			if (!height.empty()) {
				auto it = height.rbegin();
				y = it->first;
			}
			if (lastY != y) {
				res.push_back(vector<int>{x, y});
				lastY = y;
			}
		}
		return res;
	}
};

void print(vector<vector<int>>&& a)
{
	cout << "[ ";
	for (auto& r : a) {
		cout << "[ ";
		for (auto e : r) cout << e << " ";
		cout << "] ";
	}
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
		print(s.getSkyline(a)); // answer: [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]
	}
	return 0;
}
