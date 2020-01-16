// https://leetcode-cn.com/problems/set-matrix-zeroes/
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m <= 0) return;
		int n = matrix[0].size();
		if (n <= 0) return;
		unordered_set<int> r, c;
		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (matrix[y][x] == 0) {
					r.insert(y);
					c.insert(x);
				}
			}
		}
		for (auto y : r) {
			for (int x = 0; x < n; ++x) {
				matrix[y][x] = 0;
			}
		}
		for (auto x : c) {
			for (int y = 0; y < m; ++y) {
				matrix[y][x] = 0;
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (const auto& r : a) {
		printf("  [");
		int i = 0;
		for (auto e : r) {
			printf("%s%d", (i++?",":""), e);
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{1,1,1},
			{1,0,1},
			{1,1,1}
		};
		s.setZeroes(a);
		print(a);
	}
	{
		vector<vector<int>> a = {
			{0,1,2,0},
			{3,4,5,2},
			{1,3,1,5}
		};
		s.setZeroes(a);
		print(a);
	}
	return 0;
}
