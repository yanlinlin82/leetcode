// https://leetcode-cn.com/problems/word-break/
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		Node dict;
		for (auto w : wordDict) init(dict, w.c_str());
		vector<bool> m(s.size() + 1);
		m[0] = true;
		for (int i = 0; i < s.size(); ++i) {
			if (!m[i]) continue;
			vector<int> a;
			query(s.c_str() + i, dict, 0, a);
			for (int j = 0; j < a.size(); ++j) {
				m[i + a[j]] = true;
			}
		}
		return m.back();
	}
private:
	struct Node {
		char letter;
		bool is_leaf;
		map<char, Node> next;
		explicit Node(char c = 0, bool leaf = false): letter(c), is_leaf(leaf) { }
	};
	void query(const char* s, const Node& n, int i, vector<int>& a) {
		if (n.is_leaf) a.push_back(i);
		auto it = n.next.find(*s);
		if (it != n.next.end()) {
			query(s + 1, it->second, i + 1, a);
		}
	}
	void init(Node& n, const char* s) {
		if (!*s) {
			n.is_leaf = true;
		} else {
			init(n.next[*s], s + 1);
		}
	}
	void print(const Node& n, string prefix = "") {
		if (n.is_leaf) {
			printf("'%s'\n", prefix.c_str());
		}
		for (auto& [c, sub] : n.next) {
			print(sub, prefix + "->" + c);
		}
	}
};

int main()
{
	Solution sln;
	{
		string s = "leetcode";
		vector<string> wordDict = {"leet", "code"};
		printf("%d\n", sln.wordBreak(s, wordDict)); // answer: true
	}
	{
		string s = "applepenapple";
		vector<string> wordDict = {"apple", "pen"};
		printf("%d\n", sln.wordBreak(s, wordDict)); // answer: true
	}
	{
		string s = "catsandog";
		vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
		printf("%d\n", sln.wordBreak(s, wordDict)); // answer: false
	}
	return 0;
}
