// https://leetcode-cn.com/problems/valid-sudoku/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			if (!check(board[i][0], board[i][1], board[i][2],
						board[i][3], board[i][4], board[i][5],
						board[i][6], board[i][7], board[i][8])) {
				return false;
			}
		}
		for (int i = 0; i < 9; ++i) {
			if (!check(board[0][i], board[1][i], board[2][i],
						board[3][i], board[4][i], board[5][i],
						board[6][i], board[7][i], board[8][i])) {
				return false;
			}
		}
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				if (!check(board[i][j], board[i][j+1], board[i][j+2],
						board[i+1][j], board[i+1][j+1], board[i+1][j+2],
						board[i+2][j], board[i+2][j+1], board[i+2][j+2])) {
					return false;
				}
			}
		}
		return true;
	}
private:
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
		printf("%d\n", s.isValidSudoku(b)); // answer: true
	}
	{
		const char a[9][9] = {
			{'8','3','.','.','7','.','.','.','.'},
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
		printf("%d\n", s.isValidSudoku(b)); // answer: false
	}
	return 0;
}
