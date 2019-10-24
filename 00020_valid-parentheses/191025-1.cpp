// https://leetcode-cn.com/problems/valid-parentheses/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack(s.size());
		int i = -1;
		for (const char* p = s.c_str(); *p; ++p) { 
			if (*p == ')') {
				if (i >= 0 && stack[i] == '(') {
					--i;
				} else {
					return false;
				}
			} else if (*p == ']') {
				if (i >= 0 && stack[i] == '[') {
					--i;
				} else {
					return false;
				}
			} else if (*p == '}') {
				if (i >= 0 && stack[i] == '{') {
					--i;
				} else {
					return false;
				}
			} else {
				stack[++i] = *p;
			}
		}
		return (i == -1);
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isValid("()")); // answer: true
	printf("%d\n", s.isValid("()[]{}")); // answer: true
	printf("%d\n", s.isValid("(]")); // answer: false
	printf("%d\n", s.isValid("([)]")); // answer: false
	printf("%d\n", s.isValid("{[]}")); // answer: true
	printf("%d\n", s.isValid("[")); // answer: false
	printf("%d\n", s.isValid("")); // answer: true
	return 0;
}
