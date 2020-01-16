// https://leetcode-cn.com/problems/climbing-stairs/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return n;
		vector<int> a(n + 1);
		a[0] = 1;
		for (int i = 0; i + 1 <= n; ++i) {
			a[i + 1] += a[i];
			if (i + 2 <= n) {
				a[i + 2] += a[i];
			}
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.climbStairs(2)); // answer: 2
	printf("%d\n", s.climbStairs(3)); // answer: 3
	return 0;
}
