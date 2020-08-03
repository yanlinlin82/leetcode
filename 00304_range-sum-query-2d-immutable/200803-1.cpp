// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		m = matrix;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; ++i) {
			for (int j = col1; j <= col2; ++j) {
				sum += m[i][j];
			}
		}
		return sum;
	}
private:
	vector<vector<int>> m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main()
{
	{
		vector<vector<int>> m = {
			{3, 0, 1, 4, 2},
			{5, 6, 3, 2, 1},
			{1, 2, 0, 1, 5},
			{4, 1, 0, 1, 7},
			{1, 0, 3, 0, 5}
		};
		NumMatrix nm(m);
		cout << nm.sumRegion(2, 1, 4, 3) << endl; // answer: 8
		cout << nm.sumRegion(1, 1, 2, 2) << endl; // answer: 11
		cout << nm.sumRegion(1, 2, 2, 4) << endl; // answer: 12
	}
}
