// https://leetcode-cn.com/problems/maximal-square/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int maxEdge = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (matrix[i][j] == '1') {
					int e = getMaxEdge(matrix, i, j);
					if (e > maxEdge) maxEdge = e;
				}
			}
		}
		return maxEdge * maxEdge;
	}
private:
	int getMaxEdge(const vector<vector<char>>& a, int i, int j) {
		int edge = 1;
		for (;; ++edge) {
			if (i + edge >= a.size()) break;
			if (j + edge >= a[i].size()) break;
			bool ok = true;
			for (int k = 0; k <= edge; ++k) {
				if (a[i + edge][j + k] == '0') {
					ok = false;
					break;
				}
				if (a[i + k][j + edge] == '0') {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		return edge;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<char>> a = {
			{'1', '0', '1', '0', '0'},
			{'1', '0', '1', '1', '1'},
			{'1', '1', '1', '1', '1'},
			{'1', '0', '0', '1', '0'},
		};
		cout << s.maximalSquare(a) << endl; // answer: 4
	}
	{
		vector<vector<char>> a = {
			{'1', '1'},
			{'1', '1'},
		};
		cout << s.maximalSquare(a) << endl; // answer: 4
	}
	{
		vector<vector<char>> a = {
			{'0','0','0','1','0','1','1','1'},
			{'0','1','1','0','0','1','0','1'},
			{'1','0','1','1','1','1','0','1'},
			{'0','0','0','1','0','0','0','0'},
			{'0','0','1','0','0','0','1','0'},
			{'1','1','1','0','0','1','1','1'},
			{'1','0','0','1','1','0','0','1'},
			{'0','1','0','0','1','1','0','0'},
			{'1','0','0','1','0','0','0','0'}
		};
		cout << s.maximalSquare(a) << endl; // answer: 4
	}
	return 0;
}
