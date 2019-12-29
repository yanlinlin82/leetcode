// https://leetcode-cn.com/problems/n-queens-ii/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int count = 0;
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
					++count;
				} else {
					++i;
				}
			}
		}
		return count;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.totalNQueens(1));
	printf("%d\n", s.totalNQueens(2));
	printf("%d\n", s.totalNQueens(3));
	printf("%d\n", s.totalNQueens(4));
	printf("%d\n", s.totalNQueens(5));
	return 0;
}
