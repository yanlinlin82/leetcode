// https://leetcode-cn.com/problems/multiply-strings/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		int n1 = num1.size();
		int n2 = num2.size();
		string res;
		int carry = 0;
		for (int k = 0; k < n1 + n2 - 1; ++k) {
			int sum = carry;
			for (int i = 0; i <= k; ++i) {
				int j = k - i;
				if (i >= n1 || j >= n2) continue;
				sum += (num1[n1 - 1 - i] - '0') * (num2[n2 - 1 - j] - '0');
			}
			carry = sum / 10;
			res = static_cast<char>('0' + (sum % 10)) + res;
		}
		if (carry > 0) {
			res = static_cast<char>('0' + carry) + res;
		}
		return res;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.multiply("2", "3").c_str()); // answer: 6
	printf("%s\n", s.multiply("123", "456").c_str()); // answer: 56088
	printf("%s\n", s.multiply("0", "456").c_str()); // answer: 0
	printf("%s\n", s.multiply("123", "0").c_str()); // answer: 0
	printf("%s\n", s.multiply("12345678901234567890", "12345678901234567890").c_str());
	return 0;
}
