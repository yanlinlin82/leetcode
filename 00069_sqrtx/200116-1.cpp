// https://leetcode-cn.com/problems/sqrtx/
#include <cstdio>

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		for (int c = 1; c <= x; ++c) {
			int d = x / c;
			if (c == d) return c;
			if (c > d) return c - 1;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.mySqrt(4)); // answer: 2
	printf("%d\n", s.mySqrt(8)); // answer: 2

	printf("%d\n", s.mySqrt(0)); // answer: 0
	printf("%d\n", s.mySqrt(1)); // answer: 1
	printf("%d\n", s.mySqrt(2)); // answer: 1
	printf("%d\n", s.mySqrt(3)); // answer: 1
	printf("%d\n", s.mySqrt(4)); // answer: 2
	printf("%d\n", s.mySqrt(5)); // answer: 2
	printf("%d\n", s.mySqrt(6)); // answer: 2
	printf("%d\n", s.mySqrt(7)); // answer: 2
	printf("%d\n", s.mySqrt(8)); // answer: 2
	printf("%d\n", s.mySqrt(9)); // answer: 3
	printf("%d\n", s.mySqrt(10)); // answer: 3
	printf("%d\n", s.mySqrt(11)); // answer: 3
	printf("%d\n", s.mySqrt(12)); // answer: 3
	printf("%d\n", s.mySqrt(13)); // answer: 3
	printf("%d\n", s.mySqrt(14)); // answer: 3
	printf("%d\n", s.mySqrt(15)); // answer: 3
	printf("%d\n", s.mySqrt(16)); // answer: 4
	return 0;
}
