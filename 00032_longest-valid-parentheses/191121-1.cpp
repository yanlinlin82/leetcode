// https://leetcode-cn.com/problems/longest-valid-parentheses/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> stack;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == '(') {
				stack.push_back(i);
			} else {
				if (!stack.empty()) {
					int j = stack.back();
					stack.pop_back();
					s[i] = s[j] = ' ';
				}
			}
		}
		int start = -1;
		int longest = 0;
		for (int i = 0; ; ++i) {
			if (s[i] == ' ') {
				if (start < 0) {
					start = i;
				}
			} else {
				if (start >= 0) {
					int size = i - start;
					if (size > longest) {
						longest = size;
					}
				}
				start = -1;
				if (s[i] == '\0') break;
			}
		}
		return longest;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.longestValidParentheses("(()")); // answer: 2
	printf("%d\n", s.longestValidParentheses(")()())")); // answer: 4

	printf("%d\n", s.longestValidParentheses("")); // answer: 0
	printf("%d\n", s.longestValidParentheses(")")); // answer: 0
	printf("%d\n", s.longestValidParentheses("(")); // answer: 0
	printf("%d\n", s.longestValidParentheses(")(")); // answer: 0
	printf("%d\n", s.longestValidParentheses("))")); // answer: 0
	printf("%d\n", s.longestValidParentheses("))(")); // answer: 0

	printf("%d\n", s.longestValidParentheses("()")); // answer: 2
	printf("%d\n", s.longestValidParentheses("())")); // answer: 2
	printf("%d\n", s.longestValidParentheses(")()")); // answer: 2
	printf("%d\n", s.longestValidParentheses(")()(")); // answer: 2
	return 0;
}
