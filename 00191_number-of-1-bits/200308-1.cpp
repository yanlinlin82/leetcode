// https://leetcode-cn.com/problems/number-of-1-bits/
#include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int c = 0;
		for (int i = 0; i < 32; ++i) {
			c += (n % 2);
			n >>= 1;
		}
		return c;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.hammingWeight(0b00000000000000000000000000001011)); // answer: 3
	printf("%d\n", s.hammingWeight(0b00000000000000000000000010000000)); // answer: 1
	printf("%d\n", s.hammingWeight(0b11111111111111111111111111111101)); // answer: 31
	return 0;
}
