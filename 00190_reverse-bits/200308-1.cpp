// https://leetcode-cn.com/problems/reverse-bits/
#include <iostream>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t r = 0;
		for (int i = 0; i < 32; ++i) {
			r = (r << 1) | (n % 2);
			n >>= 1;
		}
		return r;
	}
};

int main()
{
	Solution s;
	printf("%u\n", s.reverseBits(43261596)); // answer: 964176192
	printf("%u\n", s.reverseBits(4294967293)); // answer: 3221225471
	return 0;
}
