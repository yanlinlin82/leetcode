// https://leetcode-cn.com/problems/spiral-matrix-ii/
#include <cstdio>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (const auto& r : a) {
		printf("  [");
		for (size_t i = 0; i < r.size(); ++i) {
			printf(" %d%s", r[i], (i + 1 < r.size() ? "," : " ]\n"));
		}
	}
	printf("]\n");
}

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> a(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(n);
		}
		for (int x = 0, y = 0, dx = 1, dy = 0, c = 1; c <= n * n; ++c) {
			a[y][x] = c;
			int x2 = x + dx;
			int y2 = y + dy;
			if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && a[y2][x2] == 0) {
				x = x2; y = y2; continue;
			}
			if (dx == 1 && dy == 0) {
				dx = 0; dy = 1;
			} else if (dx == 0 && dy == 1) {
				dx = -1; dy = 0;
			} else if (dx == -1 && dy == 0) {
				dx = 0; dy = -1;
			} else if (dx == 0 && dy == -1) {
				dx = 1; dy = 0;
			}
			x += dx; y += dy;
		}
		return a;
	}
};

int main()
{
	Solution s;
	print(s.generateMatrix(1));
	print(s.generateMatrix(2));
	print(s.generateMatrix(3));
	print(s.generateMatrix(4));
	return 0;
}
