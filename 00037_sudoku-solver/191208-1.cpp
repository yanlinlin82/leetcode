// https://leetcode-cn.com/problems/sudoku-solver/
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<pair<int,int>> cells;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					cells.push_back(make_pair(i, j));
				}
			}
		}
		for (int k = 0; k >= 0 && k < cells.size();) {
			int i = cells[k].first;
			int j = cells[k].second;
			if (board[i][j] == '9') {
				board[i][j] = '.';
				--k;
			} else {
				if (board[i][j] == '.') {
					board[i][j] = '1';
				} else {
					board[i][j]++;
				}
				if (!check(board, i, j)) {
					continue;
				}
				++k;
			}
		}
	}
private:
	bool check(vector<vector<char>>& b, int i, int j) {
		if (!check(b[i][0], b[i][1], b[i][2],
					b[i][3], b[i][4], b[i][5],
					b[i][6], b[i][7], b[i][8])) {
			return false;
		}
		if (!check(b[0][j], b[1][j], b[2][j],
					b[3][j], b[4][j], b[5][j],
					b[6][j], b[7][j], b[8][j])) {
			return false;
		}
		i -= i % 3;
		j -= j % 3;
		if (!check(b[i][j], b[i][j+1], b[i][j+2],
					b[i+1][j], b[i+1][j+1], b[i+1][j+2],
					b[i+2][j], b[i+2][j+1], b[i+2][j+2])) {
			return false;
		}
		return true;
	}
	bool check(char a, char b, char c, char d, char e,
			char f, char g, char h, char i) {
		int flag[9] = { 0 };
		if (a != '.') { if (++flag[a - '1'] > 1) return false; }
		if (b != '.') { if (++flag[b - '1'] > 1) return false; }
		if (c != '.') { if (++flag[c - '1'] > 1) return false; }
		if (d != '.') { if (++flag[d - '1'] > 1) return false; }
		if (e != '.') { if (++flag[e - '1'] > 1) return false; }
		if (f != '.') { if (++flag[f - '1'] > 1) return false; }
		if (g != '.') { if (++flag[g - '1'] > 1) return false; }
		if (h != '.') { if (++flag[h - '1'] > 1) return false; }
		if (i != '.') { if (++flag[i - '1'] > 1) return false; }
		return true;
	}
};

void assign(const char a[9][9], vector<vector<char>>& b)
{
	for (int i = 0; i < 9; ++i) {
		b.push_back(vector<char>());
		for (int j = 0; j < 9; ++j) {
			b[i].push_back(a[i][j]);
		}
	}
}

void print(vector<vector<char>>& b)
{
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Solution s;
	{
		const char a[9][9] = {
			{'5','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'}
		};
		vector<vector<char>> b;
		assign(a, b);
		s.solveSudoku(b);
		print(b);
	}
	return 0;
}
