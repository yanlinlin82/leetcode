// https://leetcode-cn.com/problems/surrounded-regions/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int h = board.size(), w = board.empty() ? 0 : board[0].size();
		for (int y = 0; y < h; ++y) {
			visit(board, w, h, 0, y);
			visit(board, w, h, w - 1, y);
		}
		for (int x = 1; x + 1 < w; ++x) {
			visit(board, w, h, x, 0);
			visit(board, w, h, x, h - 1);
		}
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (board[y][x] == 'o') {
					board[y][x] = 'O';
				} else if (board[y][x] == 'O') {
					board[y][x] = 'X';
				}
			}
		}
	}
private:
	void visit(vector<vector<char>>& a, int w, int h, int x, int y)
	{
		if (a[y][x] == 'X') return;
		if (a[y][x] == 'O') {
			a[y][x] = 'o'; 
			if (x > 0) visit(a, w, h, x - 1, y);
			if (x + 1 < w) visit(a, w, h, x + 1, y);
			if (y > 0) visit(a, w, h, x, y - 1);
			if (y + 1 < h) visit(a, w, h, x, y + 1);
		}
	}
};

void print(const vector<vector<char>>& a)
{
	for (auto r : a) {
		for (auto c : r) {
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	Solution s;
	{
		vector<vector<char>> a = {
			{ 'X', 'X', 'X', 'X' },
			{ 'X', 'O', 'O', 'X' },
			{ 'X', 'X', 'O', 'X' },
			{ 'X', 'O', 'X', 'X' },
		};
		s.solve(a);
		print(a);
	}
	{
		vector<vector<char>> a = {
			{ 'O', 'O' },
			{ 'O', 'O' },
		};
		s.solve(a);
		print(a);
	}
	return 0;
}
