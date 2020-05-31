// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(); if (n <= 0) return false;
		int m = matrix[0].size(); if (m <= 0) return false;
		return searchMatrix(matrix, target, 0, 0, m - 1, n - 1);
	}
private:
	bool searchMatrix(vector<vector<int>>& m, int target,
			int x1, int y1, int x2, int y2) {
		if (x1 > x2 || y1 > y2) {
			return false;
		} else if (x1 == x2 && y1 == y2) {
			return (m[y1][x1] == target);
		} else if (m[y1][x1] > target || m[y2][x2] < target) {
			return false;
		} else {
			int x = (x1 + x2) / 2;
			int y = (y1 + y2) / 2;
			if (m[y][x] == target) {
				return true;
			} else if (m[y][x] > target) {
				return searchMatrix(m, target, x1, y1, x - 1, y - 1) ||
					searchMatrix(m, target, x, y1, x2, y - 1) ||
					searchMatrix(m, target, x1, y, x - 1, y2);
			} else {
				return searchMatrix(m, target, x + 1, y + 1, x2, y2) ||
					searchMatrix(m, target, x1, y + 1, x, y2) ||
					searchMatrix(m, target, x + 1, y1, x2, y);
			}
		}
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{1,   4,  7, 11, 15},
			{2,   5,  8, 12, 19},
			{3,   6,  9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
		};
		cout << s.searchMatrix(a, 5) << endl; // answer: true
		cout << s.searchMatrix(a, 20) << endl; // answer: false
	}
	{
		vector<vector<int>> a = {
			{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15},
			{16,17,18,19,20},
			{21,22,23,24,25}
		};
		cout << s.searchMatrix(a, 5) << endl; // answer: true
	}
	return 0;
}
