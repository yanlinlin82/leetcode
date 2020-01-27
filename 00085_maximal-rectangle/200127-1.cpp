// https://leetcode-cn.com/problems/maximal-rectangle/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(); if (m <= 0) return 0;
		int n = matrix[0].size(); if (n <= 0) return 0;
		int max_area = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') continue;
				expandFrom(matrix, m, n, i, j, max_area);
			}
		}
		return max_area;
    }
private:
	void expandFrom(const vector<vector<char>>& matrix, int m, int n, int i, int j, int& max_area) {
		int iend = i + 1; while (iend < m && matrix[iend][j] == '1') ++iend;
		//printf("   add result: (%d, %d), [%d x %d] = %d\n", i, j, (iend - i), 1, (iend - i));
		int area = (iend - i); if (area > max_area) max_area = area;
		for (int j2 = j + 1; j2 < n; ++j2) {
			if (matrix[i][j2] == '0') break;
			int iend2 = i + 1; while (iend2 < iend && matrix[iend2][j2] == '1') ++iend2;
			int area = (iend2 - i) * (j2 - j + 1); if (area > max_area) max_area = area;
			if (iend2 < iend) {
				iend = iend2;
				//printf("   add result: (%d, %d), [%d x %d] = %d\n", i, j, (iend2 - i), (j2 - j + 1), (iend2 - i) * (j2 - j + 1));
			} else {
				//printf("update result: (%d, %d), [%d x %d] = %d\n", i, j, (iend2 - i), (j2 - j + 1), (iend2 - i) * (j2 - j + 1));
			}
		}
	}
};

int main()
{
	Solution s;
	{
		vector<vector<char>> a = {
			{'1','0','1','0','0'},
			{'1','0','1','1','1'},
			{'1','1','1','1','1'},
			{'1','0','0','1','0'}
		};
		printf("%d\n", s.maximalRectangle(a)); // answer: 6
	}
	return 0;
}
