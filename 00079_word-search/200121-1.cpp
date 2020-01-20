// https://leetcode-cn.com/problems/word-search/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		int rows = board.size(); if (rows <= 0) return false;
		int cols = board[0].size(); if (cols <= 0) return false;
		vector<vector<bool>> visited(rows);
		for (int i = 0; i < rows; ++i) { visited[i].resize(cols); }
		for (int y = 0; y < rows; ++y) {
			for (int x = 0; x < cols; ++x) {
				if (findFrom(board, rows, cols, visited, word, 0, x, y)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool findFrom(const vector<vector<char>>& board, int rows, int cols,
			vector<vector<bool>>& visited, const string& word, int pos, int x, int y) {
		if (pos >= word.size()) return true;
		if (x < 0 || x >= cols) return false;
		if (y < 0 || y >= rows) return false;
		if (visited[y][x]) return false;
		if (board[y][x] != word[pos]) return false;
		visited[y][x] = true;
		if (findFrom(board, rows, cols, visited, word, pos + 1, x - 1, y)) return true;
		if (findFrom(board, rows, cols, visited, word, pos + 1, x + 1, y)) return true;
		if (findFrom(board, rows, cols, visited, word, pos + 1, x, y - 1)) return true;
		if (findFrom(board, rows, cols, visited, word, pos + 1, x, y + 1)) return true;
		visited[y][x] = false;
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<char>> a = {
			{'A','B','C','E'},
			{'S','F','C','S'},
			{'A','D','E','E'}
		};
		printf("%d\n", s.exist(a, "ABCCED")); // answer: true
		printf("%d\n", s.exist(a, "SEE"));    // answer: true
		printf("%d\n", s.exist(a, "ABCB"));   // answer: false
	}
	return 0;
}
