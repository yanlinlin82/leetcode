// https://leetcode-cn.com/problems/add-binary/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string c = a;
		if (c.size() < b.size()) {
			c = string(b.size() - c.size(), '0') + c;
		}
		int carry = 0;
		for (int i = c.size() - 1, j = b.size() - 1; i >= 0; --i, --j) {
			if (j >= 0) {
				c[i] += (b[j] - '0');
			}
			c[i] += carry;
			if (c[i] >= '2') {
				c[i] -= 2;
				carry = 1;
			} else {
				carry = 0;
			}
		}
		if (carry) c.insert(c.begin(), '1');
		return c;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.addBinary("11", "1").c_str()); // answer: 100
	printf("%s\n", s.addBinary("1010", "1011").c_str()); // answer: 10101
	return 0;
}
