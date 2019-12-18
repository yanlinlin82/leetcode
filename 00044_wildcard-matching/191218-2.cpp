// https://leetcode-cn.com/problems/wildcard-matching/
// WARNING: this version used too much time!!
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		if (n == 0) {
			for (int i = 0; i < m; ++i) {
				if (p[i] != '*') return false;
			}
			return true;
		}
		vector<bool> x(n + 1);
		for (int i = 0; i < m; ++i) {
			vector<bool> x2(n + 1);
			char c = p[i];
			for (int j = 0; j <= n; ++j) {
				if (!(i == 0 && j == 0)) {
					if (!x[j]) continue;
				}
				if (c == '*') {
					for (int k = j; k <= n; ++k) {
						x2[k] = true;
					}
					break;
				} else if (j < n && (c == '?' || s[j] == c)) {
					x2[j + 1] = true;
				}
			}
			x = x2;
			//printf("[i = %d, c = '%c']", i, c); for (auto e : x) { printf(" %d", (e ? 1 : 0)); }; printf("\n");
		}
		return x.back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isMatch("aa", "a"));        // answer: false
	printf("%d\n", s.isMatch("aa", "*"));        // answer: true
	printf("%d\n", s.isMatch("cb", "?a"));       // answer: false
	printf("%d\n", s.isMatch("adceb", "*a*b"));  // answer: true
	printf("%d\n", s.isMatch("acdcb", "a*c?b")); // answer: false
	printf("%d\n", s.isMatch("", ""));           // answer: true
	printf("%d\n", s.isMatch("", "*"));          // answer: true
	printf("%d\n", s.isMatch("", "?"));          // answer: false
	printf("%d\n", s.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
				"*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"));
	printf("%d\n", s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
"**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
	printf("%d\n", s.isMatch("a", "a*"));        // answer: true
	return 0;
}
