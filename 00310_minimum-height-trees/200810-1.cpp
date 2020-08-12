// https://leetcode-cn.com/problems/minimum-height-trees/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> m(n);
		for (auto& r : m) {
			r.resize(n);
			for (auto& e : r) {
				e = n;
			}
		}
		for (auto& e : edges) {
			m[e[0]][e[1]] = 1;
			m[e[1]][e[0]] = 1;
		}
		for (int i = 0; i < n; ++i) {
			m[i][i] = 1;
		}
		for (;;) {
			bool flag = false;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						if (m[i][j] > m[i][k] + m[k][j]) {
							m[i][j] = m[i][k] + m[k][j];
							flag = true;
						}
					}
				}
			}
			if (!flag) break;
		}
		vector<int> depth(n);
		int max_depth = n;
		for (int i = 0; i < n; ++i) {
			depth[i] = m[i][0];
			for (int j = 1; j < n; ++j) {
				if (depth[i] < m[i][j]) {
					depth[i] = m[i][j];
				}
			}
			if (max_depth > depth[i]) {
				max_depth = depth[i];
			}
		}
#if 0
		for (auto& r : m) {
			for (auto e : r) cout << e << " "; cout << endl;
		}
#endif
		vector<int> r;
		for (int i = 0; i < n; ++i) {
			if (depth[i] == max_depth) {
				r.push_back(i);
			}
		}
		return r;
	}
};

void print(const vector<int>& a)
{
	cout << "[ ";
	for (auto& e : a) cout << e << " ";
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{1, 0}, {1, 2}, {1, 3}};
		print(s.findMinHeightTrees(4, a)); // answer: [1]
	}
	{
		vector<vector<int>> a = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
		print(s.findMinHeightTrees(6, a)); // answer: [3, 4]
	}
	return 0;
}
