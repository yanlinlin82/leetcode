// https://leetcode-cn.com/problems/longest-common-prefix/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int n = strs.size();
        if (n == 0) return "";
        const char* s = strs[0].c_str();
        const char* p = s;
        for (int len = 0; *p; ++len, ++p) {
            for (int i = 1; i < n; ++i) {
                const char* q = strs[i].c_str() + len;
                if (*q != *p) {
                    return string(s, p);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    Solution s;
    vector<string> a1{"flower","flow","flight"};
    printf("%s\n", s.longestCommonPrefix(a1).c_str()); // answer: "fl"
    vector<string> a2{"dog","racecar","car"};
    printf("%s\n", s.longestCommonPrefix(a2).c_str()); // answer: ""
    return 0;
}
