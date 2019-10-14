// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		static const char* LETTERS[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res;
		int n = digits.size();
		if (n > 0) {
			vector<const char*> dict;
			for (const char* p = digits.c_str(); *p; ++p) {
				dict.push_back(LETTERS[*p - '2']);
			}
			string buf;
			buf.resize(n);
			vector<const char*> q = dict;
			for (;;) {
				for (int i = 0; i < n; ++i) {
					buf[i] = *q[i];
				}
				res.push_back(buf);
				int i;
				for (i = n - 1; i >= 0; --i) {
					if (*(++q[i]) == '\0') {
						q[i] = dict[i];
					} else {
						break;
					}
				}
				if (i < 0) break;
			}
		}
		return res;
	}
};

void print(const vector<string>& s)
{
	printf("[");
	for (auto e : s) {
		printf(" \"%s\"", e.c_str());
	}
	printf(" ]\n");
}

int main() {
	Solution s;
	print(s.letterCombinations("23")); // answer: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	return 0;
}
