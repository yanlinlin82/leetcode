// https://leetcode-cn.com/problems/valid-number/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		const char* p = s.c_str();
		while (*p == ' ') ++p;
		if (*p == '+' || *p == '-') ++p;
		bool hasNumber = false;
		if (*p != '.') {
			if (*p < '0' || *p > '9') return false;
			while (*p >= '0' && *p <= '9') { hasNumber = true; ++p; }
		}
		if (*p == '.') {
			++p;
			while (*p >= '0' && *p <= '9') { hasNumber = true; ++p; }
		}
		if (!hasNumber) return false;
		if (*p == 'e' || *p == 'E') {
			++p;
			if (*p == '+' || *p == '-') ++p;
			if (*p < '0' || *p > '9') return false;
			while (*p >= '0' && *p <= '9') ++p;
		}
		while (*p == ' ') ++p;
		return (!*p);
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isNumber("0"));         // answer: true
	printf("%d\n", s.isNumber(" 0.1 "));     // answer: true
	printf("%d\n", s.isNumber("abc"));       // answer: false
	printf("%d\n", s.isNumber("1 a"));       // answer: false
	printf("%d\n", s.isNumber("2e10"));      // answer: true
	printf("%d\n", s.isNumber(" -90e3   ")); // answer: true
	printf("%d\n", s.isNumber(" 1e"));       // answer: false
	printf("%d\n", s.isNumber("e3"));        // answer: false
	printf("%d\n", s.isNumber(" 6e-1"));     // answer: true
	printf("%d\n", s.isNumber(" 99e2.5 "));  // answer: false
	printf("%d\n", s.isNumber("53.5e93"));   // answer: true
	printf("%d\n", s.isNumber(" --6 "));     // answer: false
	printf("%d\n", s.isNumber("-+3"));       // answer: false
	printf("%d\n", s.isNumber("95a54e53"));  // answer: false
	printf("%d\n", s.isNumber(".1"));        // answer: true
	printf("%d\n", s.isNumber("3."));        // answer: true
	printf("%d\n", s.isNumber("."));         // answer: false
	return 0;
}
