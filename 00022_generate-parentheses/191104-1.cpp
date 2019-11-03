// https://leetcode-cn.com/problems/generate-parentheses/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> r;
		process(r, n, "", 0, 0);
		return r;
    }
private:
	void process(vector<string>& r, int n, string prefix, int a, int b) {
		if (a + b == 2 * n) {
			r.push_back(prefix);
		} else {
			if (a < n) {
				process(r, n, prefix + "(", a + 1, b);
			}
			if (b < n && a > b) {
				process(r, n, prefix + ")", a, b + 1);
			}
		}
	}
};

void print(const vector<string>& s)
{
    for (auto& e : s) {
        printf("%s\n", e.c_str());
    }
}

int main()
{
    Solution s;
    print(s.generateParenthesis(3));
    return 0;
}
