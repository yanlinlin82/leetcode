// https://leetcode-cn.com/problems/unique-paths/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 1 && n <= 1) return 1;
		if (m > n) return uniquePaths(n, m);
		vector<int> a(m);
		for (int i = 0; i < m; ++i) { a[i] = 1; }
		for (int j = 1; j < n; ++j) {
			for (int i = 1; i < m; ++i) {
				a[i] += a[i - 1];
			}
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.uniquePaths(3, 2)); // answer: 3
	printf("%d\n", s.uniquePaths(7, 3)); // answer: 28
	return 0;
}
