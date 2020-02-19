// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		string res = "";
		if ((numerator < 0) != (denominator < 0)) {
			res = "-";
		}
		long long n = static_cast<long long>(numerator); if (n < 0) n = -n;
		long long d = static_cast<long long>(denominator); if (d < 0) d = -d;
		res += to_string(n / d);
		n %= d;
		if (n > 0) {
			res += ".";
			vector<int> a;
			unordered_map<int, int> b;
			int loop_start = -1;
			while (n > 0) {
				n *= 10;
				auto it = b.find(n);
				if (it != b.end()) {
					loop_start = it->second;
					break;
				}
				b.insert(make_pair(n, a.size()));
				a.push_back(n / d);
				n %= d;
			}
			for (int i = 0; i < a.size(); ++i) {
				if (i == loop_start) res += "(";
				res += to_string(a[i]);
			}
			if (loop_start >= 0) res += ")";
		}
		return res;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.fractionToDecimal(1, 2).c_str()); // answer: 0.5
	printf("%s\n", s.fractionToDecimal(2, 1).c_str()); // answer: 2
	printf("%s\n", s.fractionToDecimal(2, 3).c_str()); // answer: 0.(6)
	printf("%s\n", s.fractionToDecimal(1, 333).c_str()); // answer: 0.(003)
	printf("%s\n", s.fractionToDecimal(-1, -2147483648).c_str()); // answer: "0.0000000004656612873077392578125"
	return 0;
}
