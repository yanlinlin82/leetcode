// https://leetcode-cn.com/problems/rotate-image/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < (n + 1) / 2; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				int i2 = j;
				int j2 = n - i - 1;
				int i3 = n - i - 1;
				int j3 = n - j - 1;
				int i4 = n - j - 1;
				int j4 = i;
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i4][j4];
				matrix[i4][j4] = matrix[i3][j3];
				matrix[i3][j3] = matrix[i2][j2];
				matrix[i2][j2] = tmp;
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (auto e : a) {
		printf("  [");
		for (int i = 0; i < e.size(); ++i) {
			if (i > 0) printf(",");
			printf("%d", e[i]);
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = { {1,2,3}, {4,5,6}, {7,8,9} };
		s.rotate(a);
		print(a);
	}
	{
		vector<vector<int>> a = {
			{ 5, 1, 9,11},
			{ 2, 4, 8,10},
			{13, 3, 6, 7},
			{15,14,12,16}
		};
		s.rotate(a);
		print(a);
	}
	return 0;
}
