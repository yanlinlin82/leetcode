// https://leetcode-cn.com/problems/pascals-triangle/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows > 0) {
			vector<int> a;
			for (int i = 0; i < numRows; ++i) {
				vector<int> b;
				for (int j = 0; j < a.size(); ++j) {
					b.push_back(j == 0 ? 1 : a[j - 1] + a[j]);
				}
				b.push_back(1);
				res.push_back(b);
				a = b;
			}
		}
		return res;
    }
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (const auto& r : a) {
		printf("  [ ");
		for (auto e : r) printf("%d ", e);
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	print(s.generate(5));
	return 0;
}
