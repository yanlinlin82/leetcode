// https://leetcode-cn.com/problems/regular-expression-matching/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct PatternNode {
	char c;
	bool star;
	PatternNode(char ch, bool is_star) : c(ch), star(is_star) { }
};
struct MatchResult {
	int pos;
	int size;
};

class Solution {
public:
    bool isMatch(string s, string p) {
		vector<PatternNode> e;
		for (const char* t = p.c_str(); *t; ++t) {
			bool star = (*(t + 1) == '*');
			e.push_back(PatternNode(*t, star));
			if (star) ++t;
		}
        vector<MatchResult> m(e.size()); // [ { start, size }, ... ]
        for (int pos = 0, i = 0;;) {
            // match forward
            for (; i < e.size(); ++i) {
                if (e[i].c == '.') {
                    if (e[i].star) {
						m[i].pos = pos;
						m[i].size = s.size() - pos;
                        pos = s.size();
                    } else if (pos < s.size()) {
						m[i].pos = pos;
						m[i].size = 1;
                        ++pos;
                    } else {
                        break;
                    }
                } else {
                    if (e[i].star) {
                        int k = 0;
                        while (pos + k < s.size() && s[pos + k] == e[i].c) {
                            ++k;
                        }
						m[i].pos = pos;
						m[i].size = k;
                        pos += k;
                    } else if (pos < s.size() && s[pos] == e[i].c) {
						m[i].pos = pos;
						m[i].size = 1;
                        ++pos;
                    } else {
                        break;
                    }
                }
            }
            if (pos >= s.size() && i >= e.size()) return true;
            // backtrace
            for (;;) {
				if (i <= 0) return false; // backtrace failure
                if (e[i - 1].star && m[i - 1].size > 0) {
                    --m[i - 1].size;
                    pos = m[i - 1].pos + m[i - 1].size;
                    break;
                }
                --i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.isMatch("aa", "a")); // answer: false
    printf("%d\n", s.isMatch("aa", "a*")); // answer: true
    printf("%d\n", s.isMatch("ab", ".*")); // answer: true
    printf("%d\n", s.isMatch("aab", "c*a*b")); // answer: true
    printf("%d\n", s.isMatch("mississippi", "mis*is*p*.")); // answer: false
    return 0;
}
