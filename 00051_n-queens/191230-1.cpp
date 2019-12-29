// https://leetcode-cn.com/problems/n-queens/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		if (n > 0) {
			vector<int> m;
			for (int i = 0; i < n; ++i) {
				m.push_back(-1);
			}
			int i = 0;
			for (;;) {
next:
				if (++m[i] >= n) {
					m[i] = -1;
					if (--i < 0) break;
					continue;
				}
				for (int j = 0; j < i; ++j) {
					if (m[j] == m[i]) goto next;
					if (abs(m[j] - m[i]) == abs(j - i)) goto next;
				}
				if (i == n - 1) {
					vector<string> ans;
					for (int j = 0; j < n; ++j) {
						string line = "Q";
						if (m[j] > 0) line = string(m[j], '.') + line;
						if (m[j] < n - 1) line = line + string(n - 1 - m[j], '.');
						ans.push_back(line);
					}
					res.push_back(ans);
				} else {
					++i;
				}
			}
		}
		return res;
	}
};

void print(int n, const vector<vector<string>>& a)
{
	printf("========= %d-queens ========\n", n);
	printf("%zd solve(s)\n", a.size());
	printf("[\n");
	for (auto& m : a) {
		printf(" [");
		int i = 0;
		for (auto& l : m) {
			if (i > 0) printf("  ");
			printf("%s", l.c_str());
			if (++i < m.size()) printf(",\n");
		}
		printf("],\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	print(1, s.solveNQueens(1));
	print(2, s.solveNQueens(2));
	print(3, s.solveNQueens(3));
	print(4, s.solveNQueens(4));
	print(5, s.solveNQueens(5));
	return 0;
}
