// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> stack;
		for (int i = 0; i < tokens.size(); ++i) {
			const string& s = tokens[i];
			if (s == "+") {
				int b = stack.back(); stack.pop_back();
				int a = stack.back(); stack.pop_back();
				stack.push_back(a + b);
			} else if (s == "-") {
				int b = stack.back(); stack.pop_back();
				int a = stack.back(); stack.pop_back();
				stack.push_back(a - b);
			} else if (s == "*") {
				int b = stack.back(); stack.pop_back();
				int a = stack.back(); stack.pop_back();
				stack.push_back(a * b);
			} else if (s == "/") {
				int b = stack.back(); stack.pop_back();
				int a = stack.back(); stack.pop_back();
				stack.push_back(a / b);
			} else {
				stack.push_back(stoi(s));
			}
		}
		return stack.back();
	}
};

int main()
{
	Solution s;
	{
		vector<string> a = {"2", "1", "+", "3", "*"};
		printf("%d\n", s.evalRPN(a)); // answer: 9  - explain: ((2 + 1) * 3) = 9
	}
	{
		vector<string> a = {"4", "13", "5", "/", "+"};
		printf("%d\n", s.evalRPN(a)); // answer: 6  - explain: (4 + (13 / 5)) = 6
	}
	{
		vector<string> a = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
		printf("%d\n", s.evalRPN(a)); // answer: 22  - explain: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
	}
	return 0;
}
