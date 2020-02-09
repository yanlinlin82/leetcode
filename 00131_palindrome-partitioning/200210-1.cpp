// https://leetcode-cn.com/problems/palindrome-partitioning/
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> a;
		vector<string> p;
		partition(s.c_str(), s.size(), p, a);
		return a;
	}
private:
	void partition(const char* s, int n, vector<string>& prefix, vector<vector<string>>& res) {
		if (n <= 0) {
			if (!prefix.empty()) {
				res.push_back(prefix);
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				if (is_palindrome(s, i)) {
					prefix.push_back(string(s, s + i));
					partition(s + i, n - i, prefix, res);
					prefix.pop_back();
				}
			}
		}
	}
	bool is_palindrome(const char* s, int n) {
		if (n <= 1) return true;
		const char* t = s + n - 1;
		while (s < t) {
			if (*s++ != *t--) return false;
		}
		return true;
	}
};

void print(const vector<vector<string>>& a)
{
	printf("[\n");
	for (auto& r : a) {
		printf("  [ ");
		for (auto e : r) {
			printf("'%s' ", e.c_str());
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	print(s.partition("aab")); // answer: [ ["aa","b"], ["a","a","b"] ]
	print(s.partition("")); // answer: [ ]
	print(s.partition("a")); // answer: [ ["a"] ]
	print(s.partition("aa")); // answer: [ ["a","a"], ["aa"] ]
	return 0;
}
