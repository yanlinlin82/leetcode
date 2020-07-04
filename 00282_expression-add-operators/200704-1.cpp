// https://leetcode-cn.com/problems/expression-add-operators/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<string>&& a)
{
	cout << "[ ";
	for (auto s : a) cout << "\"" << s << "\" ";
	cout << "]" << endl;
}

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> a;
		process(a, num.substr(0, 1), num.c_str() + 1, target);
		return a;
	}
private:
	void process(vector<string>& a, string s, const char* p, int target) {
		if (*p) {
			process(a, s + *p, p + 1, target);
			process(a, s + "+" + *p, p + 1, target);
			process(a, s + "-" + *p, p + 1, target);
			process(a, s + "*" + *p, p + 1, target);
		} else {
			try {
				if (eval_exp(s.c_str()) == target) {
					a.push_back(s);
				}
			} catch (std::runtime_error&) {
			}
		}
	}
	int eval_exp(string s) {
		const char* p = s.c_str();
		int a = (int)eval_exp(p);
		//cout << "eval: " << s << " => " << a << endl;
		return a;
	}
	long long eval_exp(const char*& p) {
		long long a = eval_item(p);
		while (*p == '+' || *p == '-') {
			char c = *p++;
			long long b = eval_item(p);
			if (c == '+') {
				a += b;
			} else if (c == '-') {
				a -= b;
			}
		}
		return a;
	}
	long long eval_item(const char*& p) {
		long long a = eval_num(p);
		while (*p == '*') {
			char c = *p++;
			long long b = eval_num(p);
			if (c == '*') {
				a *= b;
			}
		}
		return a;
	}
	long long eval_num(const char*& p) {
		long long a = 0;
		if (*p == '0' && *(p+1) >= '0' && *(p+1) <= '9') {
			throw std::runtime_error("bad number");
		}
		while (*p >= '0' && *p <= '9') {
			a = a * 10 + (*p - '0');
			++p;
		}
		return a;
	}
};

int main()
{
	Solution s;
	print(s.addOperators("123", 6)); // answer: ["1+2+3", "1*2*3"]
	print(s.addOperators("232", 8)); // answer: ["2*3+2", "2+3*2"]
	print(s.addOperators("105", 5)); // answer: ["1*0+5","10-5"]
	print(s.addOperators("00", 0)); // answer: ["0+0", "0-0", "0*0"]
	print(s.addOperators("3456237490", 9191)); // answer: []
	print(s.addOperators("1000000009", 9)); // answer:
	return 0;
}
