// https://leetcode-cn.com/problems/length-of-last-word/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		const char* p = s.c_str();
		const char* q = p + s.size() - 1;
		while (q >= p && *q == ' ') --q;
		if (q < p) return 0;
		int c = 0;
		while (q >= p && *q != ' ') { --q; ++c; }
		return c;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.lengthOfLastWord("Hello World"));
	return 0;
}
