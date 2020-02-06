// https://leetcode-cn.com/problems/pascals-triangle-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> a{1};
		for (int i = 0; i < rowIndex; ++i) {
			vector<int> b;
			for (int j = 0; j < a.size(); ++j) {
				b.push_back(j == 0 ? 1 : a[j - 1] + a[j]);
			}
			b.push_back(1);
			a = b;
		}
		return a;

	}
};

void print(const vector<int>& a)
{
	printf("[ "); for (auto e : a) printf("%d ", e); printf("]\n");
}

int main()
{
	Solution s;
	print(s.getRow(3));
	return 0;
}
