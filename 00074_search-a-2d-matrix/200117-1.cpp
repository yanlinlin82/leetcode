// https://leetcode-cn.com/problems/search-a-2d-matrix/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m <= 0) return false;
		int n = matrix[0].size();
		if (n <= 0) return false;
		int i = 0;
		int j = m * n - 1;
		while (i <= j) {
			int k = (i + j) / 2;
			int y = k / n;
			int x = k % n;
			int value = matrix[y][x];
			if (value == target) return true;
			if (value < target) {
				i = k + 1;
			} else {
				j = k - 1;
			}
		}
		return false;
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
			{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}
		};
		printf("%d\n", s.searchMatrix(a, 3)); // answer: true
	}
	{
		vector<vector<int>> a = {
			{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}
		};
		printf("%d\n", s.searchMatrix(a, 13)); // answer: false
	}
	return 0;
}
