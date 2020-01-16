// https://leetcode-cn.com/problems/edit-distance/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		if (m <= 0) return n;
		if (n <= 0) return m;
		vector<vector<int>> a(m + 1);
		for (int i = 0; i <= m; ++i) {
			a[i].resize(n + 1);
		}
		for (int i = 1; i <= m; ++i) {
			a[i][0] = i;
		}
		for (int j = 1; j <= n; ++j) {
			a[0][j] = j;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = a[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
				if (a[i - 1][j] + 1 < a[i][j]) {
					a[i][j] = a[i - 1][j] + 1;
				}
				if (a[i][j - 1] + 1 < a[i][j]) {
					a[i][j] = a[i][j - 1] + 1;
				}
			}
		}
		return a.back().back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.minDistance("horse", "ros")); // answer: 3
	printf("%d\n", s.minDistance("intention", "execution")); // answer: 5
	return 0;
}
