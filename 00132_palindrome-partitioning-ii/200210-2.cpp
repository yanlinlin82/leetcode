// https://leetcode-cn.com/problems/palindrome-partitioning-ii/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		if (n <= 1) return 0;
		unordered_map<int, unordered_set<int>> a; // [ index => [size] ]
		for (int i = 0; i < n; ++i) {
			for (int w = 0; i - w >= 0 && i + w < n; ++w) {
				if (s[i - w] != s[i + w]) break;
				a[i - w].insert(1 + w * 2);
			}
			for (int w = 0; i - w >= 0 && i + 1 + w < n; ++w) {
				if (s[i - w] != s[i + 1 + w]) break;
				a[i - w].insert(2 + w * 2);
			}
		}
		vector<int> b(n + 1);
		for (int i = 0; i < n; ++i) {
			for (auto s : a[i]) {
				if (b[i + s] == 0 || b[i + s] > b[i] + 1) {
					b[i + s] = b[i] + 1;
				}
			}
		}
		return b.back() - 1;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.minCut("aab")); // answer: 1
	printf("%d\n", s.minCut("")); // answer: 0
	printf("%d\n", s.minCut("a")); // answer: 0
	printf("%d\n", s.minCut("aa")); // answer: 0
	printf("%d\n", s.minCut("abaca")); // answer: 2
	printf("%d\n", s.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp")); // answer:
	return 0;
}

