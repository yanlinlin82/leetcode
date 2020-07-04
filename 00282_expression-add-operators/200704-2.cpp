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
		const char* p = num.c_str();
		string s(1, *p);
		int value = *p - '0';
		process(a, s, value, 1, value, p + 1, target);
		return a;
	}
private:
	void process(vector<string>& a, string s,
			int value, int last_factor, int last_value,
			const char* p, int target) {
		if (*p) {
			if (last_value != 0) {
				long long x = (long long)last_value * 10 + (*p - '0');
				long long v = value + last_factor * (x - last_value);
				if (x <= numeric_limits<int>::max() && v <= numeric_limits<int>::max()) {
					process(a, s + *p, (int)v, last_factor, (int)x, p + 1, target);
				}
			}
			int x = *p - '0';
			process(a, s + "+" + *p, value + x, 1, x, p + 1, target);
			process(a, s + "-" + *p, value - x, -1, x, p + 1, target);
			long long v = value + last_factor * ((long long)last_value * x - last_value);
			if (v <= numeric_limits<int>::max()) {
				process(a, s + "*" + *p, (int)v, last_factor * last_value, x, p + 1, target);
			}
		} else if (value == target) {
			a.push_back(s);
		}
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
	print(s.addOperators("123456789", 45)); // answer: [ ... ]
	print(s.addOperators("1000000009", 9)); // answer: [ ... ]
	print(s.addOperators("2147483647", 2147483647)); // answer: [ ... ]
	print(s.addOperators("2147483648", -2147483648)); // answer: [ ... ]
	print(s.addOperators("3456237490", 9191)); // answer: [ ... ]
	return 0;
}

