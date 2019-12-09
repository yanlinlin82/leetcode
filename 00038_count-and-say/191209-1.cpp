// https://leetcode-cn.com/problems/count-and-say/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 1) {
			return "1";
		} else {
			string s = countAndSay(n - 1);
			string r;
			char c = 0;
			char n = '0';
			for (const char* p = s.c_str(); *p; ++p) {
				if (*p != c) {
					if (n > '0') {
						r += n;
						r += c;
					}
					c = *p;
					n = '1';
				} else {
					++n;
				}
			}
			if (n > '0') {
				r += n;
				r += c;
			}
			return r;
		}
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.countAndSay(1).c_str()); // answer: 1
	printf("%s\n", s.countAndSay(2).c_str()); // answer: 11
	printf("%s\n", s.countAndSay(3).c_str()); // answer: 21
	printf("%s\n", s.countAndSay(4).c_str()); // answer: 1211
	printf("%s\n", s.countAndSay(5).c_str()); // answer: 111221
	return 0;
}
