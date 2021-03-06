// https://leetcode-cn.com/problems/basic-calculator/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int pos = 0;
		return eval_exp(s.c_str(), pos);
	}
private:
	int eval_exp(const char* s, int& pos) {
		int x = eval_item(s, pos);
		for (;;) {
			skip_spaces(s, pos);
			if (s[pos] == '+') {
				int x2 = eval_item(s, ++pos);
				x += x2;
			} else if (s[pos] == '-') {
				int x2 = eval_item(s, ++pos);
				x -= x2;
			} else {
				break;
			}
		}
		return x;
	}
	int eval_item(const char* s, int& pos) {
		skip_spaces(s, pos);
		if (s[pos] == '(') {
			int x = eval_exp(s, ++pos);
			skip_spaces(s, pos);
			if (s[pos] == ')') ++pos;
			return x;
		} else if (s[pos] == '+' || s[pos] == '-') {
			bool minus = (s[pos] == '-');
			int x = eval_item(s, ++pos);
			if (minus) x = -x;
			return x;
		} else {
			int x = s[pos] - '0';
			for (++pos; s[pos] >= '0' && s[pos] <= '9'; ++pos) {
				x = x * 10 + (s[pos] - '0');
			}
			return x;
		}
	}
	void skip_spaces(const char* s, int& pos) {
		while (s[pos] == ' ') ++pos;
	}
};

int main()
{
	Solution s;
	cout << s.calculate("1 + 1") << endl; // answer: 2
	cout << s.calculate(" 2-1 + 2 ") << endl; // answer: 3
	cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl; // answer: 23
	return 0;
}
