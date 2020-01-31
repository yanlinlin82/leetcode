// https://leetcode-cn.com/problems/unique-binary-search-trees/
#include <cstdio>

class Solution {
public:
	int numTrees(int n) {
		return numTrees(1, n);
	}
private:
	int numTrees(int start, int end) {
		if (start >= end) {
			return 1;
		} else if (start + 1 == end) {
			return 2;
		} else {
			int sum = 0;
			for (int i = start; i <= end; ++i) {
				sum += numTrees(start, i - 1) * numTrees(i + 1, end);
			}
			return sum;
		}
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.numTrees(3)); // 5
	return 0;
}
