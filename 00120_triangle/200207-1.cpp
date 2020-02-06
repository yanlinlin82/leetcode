// https://leetcode-cn.com/problems/triangle/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		vector<int> a{triangle[0][0]};
		for (int i = 1; i < triangle.size(); ++i) {
			vector<int> b;
			for (int j = 0; j < triangle[i].size(); ++j) {
				if (j == 0) {
					b.push_back(a[j] + triangle[i][j]);
				} else if (j + 1 < triangle[i].size()) {
					b.push_back(min(a[j-1], a[j]) + triangle[i][j]);
				} else {
					b.push_back(a[j-1] + triangle[i][j]);
				}
			}
			a = b;
		}
		int n = a[0];
		for (int i = 1; i < a.size(); ++i) {
			if (n > a[i]) n = a[i];
		}
		return n;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {
			{2},
			{3,4},
			{6,5,7},
			{4,1,8,3}
		};
		printf("%d\n", s.minimumTotal(a)); // answer: 11 (2 + 3 + 5 + 1 = 11)
	}
	return 0;
}
