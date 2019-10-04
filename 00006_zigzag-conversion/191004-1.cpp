// https://leetcode-cn.com/problems/zigzag-conversion/
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		const char* p = s.c_str();
		int n = s.size();
		int step = (numRows - 1) * 2;
		string r;
		r.resize(n);
		int t = 0;
		for (int j = 0; j < numRows; ++j) {
			for (int i = 0; i < n + numRows; i += step) {
				for (int k = ((j == 0 || j == (numRows - 1)) ? 1 : -1); k <= 1; k += 2) {
					int index = i + k * j;
					if (index >= 0 && index < n) {
						r[t++] = p[index];
					}
				}
			}
		}
		return r;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.convert("LEETCODEISHIRING", 3).c_str()); // answer: "LCIRETOESIIGEDHN"
	printf("%s\n", s.convert("LEETCODEISHIRING", 4).c_str()); // answer: "LDREOEIIECIHNTSG"
	printf("%s\n", s.convert("LEETCODEISHIRING", 1).c_str()); // answer: "LEETCODEISHIRING"
	return 0;
}
