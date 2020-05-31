// https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(const vector<T>& a)
{
	for (auto& e : a) {
		cout << e << " ";
	}
	cout << endl;
}

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		//cout << input << endl;
		vector<int> num;
		vector<char> op;
		int n = 0;
		for (int i = 0; i < input.size(); ++i) {
			char c = input[i];
			if (c >= '0' && c <= '9') {
				n = n * 10 + (c - '0');
			} else {
				num.push_back(n);
				n = 0;
				op.push_back(c);
			}
		}
		num.push_back(n);
		//print(num);
		//print(op);
		return compute(num, op, 0, op.size());
	}
private:
	vector<int> compute(const vector<int>& num, const vector<char>& op, int start, int end) {
		vector<int> res;
		if (start >= end) {
			res.push_back(num[start]);
		} else {
			for (int k = start; k < end; ++k) {
				vector<int> a = compute(num, op, start, k);
				vector<int> b = compute(num, op, k + 1, end);
				char c = op[k];
				for (int i = 0; i < a.size(); ++i) {
					for (int j = 0; j < b.size(); ++j) {
						switch (c) {
						case '+': res.push_back(a[i] + b[j]); break;
						case '-': res.push_back(a[i] - b[j]); break;
						case '*': res.push_back(a[i] * b[j]); break;
						}
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	print(s.diffWaysToCompute("2-1-1")); // answer: [0,2]
	print(s.diffWaysToCompute("2*3-4*5")); // answer: [-34, -14, -10, -10, 10]
	print(s.diffWaysToCompute("13+5-8")); // answer: [10,10]
	return 0;
}
