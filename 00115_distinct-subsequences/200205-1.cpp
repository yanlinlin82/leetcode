// https://leetcode-cn.com/problems/distinct-subsequences/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.size();
		if (n <= 0) return 0;
		vector<long int> a(n + 1), b(n + 1);
		for (int i = 0; i <= n; ++i) a[i] = 1;
		for (size_t i = 0; i < t.size(); ++i) {
			char c = t[i];
			b[0] = 0;
			for (size_t j = 0; j < n; ++j) {
				b[j + 1] = b[j] + (c == s[j] ? a[j] : 0);
			}
			a = b;
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.numDistinct("rabbbit", "rabbit")); // answer: 3
	printf("%d\n", s.numDistinct("babgbag", "bag")); // answer: 5
	return 0;
}
