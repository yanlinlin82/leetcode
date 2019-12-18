// https://leetcode-cn.com/problems/wildcard-matching/
// WARNING: this version used too much time!!
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		string p2;
		bool star = false;
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == '*') {
				if (!star) {
					p2 += '*';
					star = true;
				}
			} else {
				p2 += p[i];
				star = false;
			}
		}
		return isMatch2(s, p2);
	}
private:
	bool isMatch2(string s, string p) {
		int n = s.size();
		int m = p.size();
		vector<Rec> rec;
		for (int i = 0, j = 0;;) {
			//printf("s = '%s', p = '%s', i = %d, j = %d ('%c' and '%c')\n", s.c_str(), p.c_str(), i, j, s[i], p[j]);
			if (i == n && j == m) return true;
			if (i <= n && j < m) {
				int c = p[j];
				if (c == '*') {
					rec.push_back(Rec(i, j, n - i));
					i = n;
					++j;
					continue;
				} else if (c == '?' || (i < n && s[i] == p[j])) {
					++i;
					++j;
					continue;
				}
			}
			for (;;) {
				if (rec.empty()) return false;
				auto& e = rec.back();
				if (e.m > 0) {
					--e.m;
					i = e.i + e.m;
					j = e.j + 1;
					break;
				} else {
					rec.pop_back();
				}
			}
		}
		return false;
	}
private:
	struct Rec {
		int i, j, m;
		Rec(int ii, int jj, int mm): i(ii), j(jj), m(mm) { }
	};
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
	return 0;
}
