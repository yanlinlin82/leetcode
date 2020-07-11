// https://leetcode-cn.com/problems/game-of-life/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int n = board.size();
		int m = board[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int x = 0;
				if (i     > 0 && j     > 0) x += (board[i - 1][j - 1] % 2);
				if (i     > 0             ) x += (board[i - 1][j    ] % 2);
				if (i     > 0 && j + 1 < m) x += (board[i - 1][j + 1] % 2);
				if (             j     > 0) x += (board[i    ][j - 1] % 2);
				if (             j + 1 < m) x += (board[i    ][j + 1] % 2);
				if (i + 1 < n && j     > 0) x += (board[i + 1][j - 1] % 2);
				if (i + 1 < n             ) x += (board[i + 1][j    ] % 2);
				if (i + 1 < n && j + 1 < m) x += (board[i + 1][j + 1] % 2);
				if ((x == 2 && (board[i][j] % 2)) || x == 3) {
					board[i][j] |= 2;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] /= 2;
			}
		}
	}
};

void print(const vector<vector<int>>& a) {
	cout << "[" << endl;
	for (const auto& r : a) {
		cout << "  [";
		for (auto e : r) {
			cout << " " << e;
		}
		cout << " ]" << endl;
	}
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{0,1,0},
			{0,0,1},
			{1,1,1},
			{0,0,0}
		};
		s.gameOfLife(a);
		print(a);
	}
	return 0;
}
