// https://leetcode-cn.com/problems/regular-expression-matching/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pair<char, bool>> e; // [ { character, is_star }, ... ]
        for (int i = 0; i < p.size(); ++i) {
            bool star = ((i + 1 < p.size()) && p[i + 1] == '*');
            e.push_back(make_pair(p[i], star));
            if (star) ++i;
        }
        vector<pair<int, int>> m; // [ { start, size }, ... ]
        for (int pos = 0, i = 0;;) {
            // match forward
            for (; i < e.size(); ++i) {
                if (e[i].first == '.') {
                    if (e[i].second) { // is_star
                        m.push_back(make_pair(pos, s.size() - pos));
                        pos = s.size();
                    } else if (pos < s.size()) {
                        m.push_back(make_pair(pos, 1));
                        ++pos;
                    } else {
                        break;
                    }
                } else {
                    if (e[i].second) { // is_star
                        int k = 0;
                        while (pos + k < s.size() && s[pos + k] == e[i].first) {
                            ++k;
                        }
                        m.push_back(make_pair(pos, k));
                        pos += k;
                    } else if (pos < s.size() && s[pos] == e[i].first) {
                        m.push_back(make_pair(pos, 1));
                        ++pos;
                    } else {
                        break;
                    }
                }
            }
            if (pos >= s.size() && i >= e.size()) return true;
            // backtrace
            for (;;) {
                if (m.empty()) return false; // backtrace failure
                auto& b = m.back();
                if (e[i - 1].second && b.second > 0) {
                    --b.second;
                    pos = b.first + b.second;
                    break;
                }
                m.pop_back();
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
