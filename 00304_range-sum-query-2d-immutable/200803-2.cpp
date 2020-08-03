// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>>& m) {
	for (auto r : m) {
		for (auto e : r) {
			cout << e << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		m.resize(matrix.size());
		for (int i = 0; i < matrix.size(); ++i) {
			m[i].resize(matrix[i].size());
		}
		for (int i = 0; i < m.size(); ++i) {
			for (int j = 0; j < m[i].size(); ++j) {
				if (i == 0 && j == 0) {
					m[i][j] = matrix[i][j];
				} else if (i == 0 && j > 0) {
					m[i][j] = m[i][j - 1] + matrix[i][j];
				} else if (i > 0 && j == 0) {
					m[i][j] = m[i - 1][j] + matrix[i][j];
				} else {
					m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + matrix[i][j];
				}
			}
		}
		print(matrix);
		print(m);
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = m[row2][col2];
		if (row1 > 0 && col1 > 0) {
			sum -= m[row1 - 1][col2] + m[row2][col1 - 1] - m[row1 - 1][col1 - 1];
		} else if (row1 > 0) {
			sum -= m[row1 - 1][col2];
		} else if (col1 > 0) {
			sum -= m[row2][col1 - 1];
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
	{
		vector<vector<int>> m = {
			{-4, -5}
		};
		NumMatrix nm(m);
		cout << nm.sumRegion(0, 0, 0, 0) << endl; // answer: -4
		cout << nm.sumRegion(0, 0, 0, 1) << endl; // answer: -9
		cout << nm.sumRegion(0, 1, 0, 1) << endl; // answer: -5
	}
}
