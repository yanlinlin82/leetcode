// https://leetcode-cn.com/problems/additive-number/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		int n = num.size();
		for (int a = 1; a < n; ++a) {
			for (int b = 1; b < n; ++b) {
				if (check(num.c_str(), n, 0, a, b)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool check(const char* s, int n, int start, int a, int b) {
		//cout << "check: " << s << ", " << n << ", " << start << ", " << a << ", " << b << endl;
		if (start + a + b > n) {
			return false;
		}
		if (a > 1 && s[start] == '0') {
			return false;
		}
		if (b > 1 && s[start + a] == '0') {
			return false;
		}
		string r;
		int c = 0;
		for (int i = 1; i <= a || i <= b; ++i) {
			int x = c;
			if (i <= a) {
				x += (s[start + a - i] - '0');
			}
			if (i <= b) {
				x += (s[start + a + b - i] - '0');
			}
			if (x >= 10) {
				c = 1;
				x %= 10;
			} else {
				c = 0;
			}
			r = static_cast<char>('0' + x) + r;
		}
		if (c > 0) {
			r = '1' + r;
		}
		//cout << ": " << string(s + start, s + start + a) << " + " << string(s + start + a, s + start + a + b) << " = " << r << endl;
		if (start + a + b + r.size() > n) {
			return false;
		}
		if (r != string(s + start + a + b, s + start + a + b + r.size())) {
			return false;
		}
		if (start + a + b + r.size() == n) {
			return true;
		}
		return check(s, n, start + a, b, r.size());
	}
};

int main()
{
	Solution s;
	cout << s.isAdditiveNumber("112358") << endl; // answer: true
	cout << s.isAdditiveNumber("199100199") << endl; // answer: true
	cout << s.isAdditiveNumber("199001200") << endl; // answer: false
	return 0;
}
