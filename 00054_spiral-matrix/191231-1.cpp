// https://leetcode-cn.com/problems/spiral-matrix/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> a;
		int h = matrix.size();
		int w = (h <= 0 ? 0 : matrix.front().size());
		visit(a, matrix, w, h, 0, 0);
		return a;
	}
private:
	void visit(vector<int>& a, const vector<vector<int>>& m, int w, int h, int x, int y)
	{
		if (h <= 0 || w <= 0) return;
		if (h == 1) {
			for (int i = 0; i < w; ++i) {
				a.push_back(m[y][x + i]);
			}
		} else if (w == 1) {
			for (int i = 0; i < h; ++i) {
				a.push_back(m[y + i][x]);
			}
		} else {
			for (int i = 0; i < w - 1; ++i) {
				a.push_back(m[y][x + i]);
			}
			for (int i = 0; i < h - 1; ++i) {
				a.push_back(m[y + i][x + w - 1]);
			}
			for (int i = w - 1; i > 0; --i) {
				a.push_back(m[y + h - 1][x + i]);
			}
			for (int i = h - 1; i > 0; --i) {
				a.push_back(m[y + i][x]);
			}
			visit(a, m, w - 2, h - 2, x + 1, y + 1);
		}
	}
};

void print(const vector<int>& a)
{
	printf("[");
	for (const auto& e : a) {
		printf(" %d", e);
	}
	printf(" ]\n");
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{1,2,3},
			{4,5,6},
			{7,8,9}
		};
		print(s.spiralOrder(a));
	}
	{
		vector<vector<int>> a = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}
		};
		print(s.spiralOrder(a));
	}
	{
		vector<vector<int>> a = {
			{1,2,3,4},
		};
		print(s.spiralOrder(a));
	}
	{
		vector<vector<int>> a = {
		};
		print(s.spiralOrder(a));
	}
	{
		vector<vector<int>> a = {
			{1}, {2}, {3}, {4}
		};
		print(s.spiralOrder(a));
	}
	{
		vector<vector<int>> a = {
			{1,2,3,4,5},
			{6,7,8,9,10}
		};
		print(s.spiralOrder(a));
	}
	return 0;
}
