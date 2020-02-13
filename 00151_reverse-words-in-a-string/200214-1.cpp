// https://leetcode-cn.com/problems/reverse-words-in-a-string/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string r;
		const char* p = s.c_str();
		while (*p) {
			while (*p == ' ') ++p;
			const char* start = p;
			while (*p && *p != ' ') ++p;
			const char* end = p;
			if (end > start) {
				if (!r.empty()) r = " " + r;
				r = string(start, end) + r;
			}
		}
		return r;
	}
};

int main()
{
	Solution s;
	printf("'%s'\n", s.reverseWords("the sky is blue").c_str()); // answer: "blue is sky the"
	printf("'%s'\n", s.reverseWords("  hello world!  ").c_str()); // answer: "world! hello"
	printf("'%s'\n", s.reverseWords("a good   example").c_str()); // answer: "example good a"
	return 0;
}
