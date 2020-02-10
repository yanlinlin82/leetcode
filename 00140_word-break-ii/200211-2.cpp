// https://leetcode-cn.com/problems/word-break-ii/
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		Node dict;
		for (auto w : wordDict) init(dict, w.c_str());
		vector<bool> m(s.size() + 1);
		vector<vector<int>> m2(s.size());
		m[0] = true;
		for (int i = 0; i < s.size(); ++i) {
			if (!m[i]) continue;
			query(s.c_str() + i, dict, 0, m2[i]);
			for (int j = 0; j < m2[i].size(); ++j) {
				m[i + m2[i][j]] = true;
			}
		}
		vector<string> res;
		if (m.back()) {
			visit(s.c_str(), s.size(), m2, 0, "", res);
		}
		return res;
	}
private:
	struct Node {
		char letter;
		bool is_leaf;
		map<char, Node> next;
		explicit Node(char c = 0, bool leaf = false): letter(c), is_leaf(leaf) { }
	};
	void query(const char* s, const Node& node, int i, vector<int>& a) {
		if (node.is_leaf) a.push_back(i);
		auto it = node.next.find(*s);
		if (it != node.next.end()) {
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
	void visit(const char* s, int n, const vector<vector<int>>& m2, int i,
			string prefix, vector<string>& res) {
		if (n <= 0) {
			res.push_back(prefix);
		} else {
			if (!prefix.empty()) prefix += " ";
			for (int j = m2[i].size() - 1; j >= 0; --j) {
				int k = m2[i][j];
				visit(s + k, n - k, m2, i + k, prefix + string(s, s + k), res);
			}
		}
	}
};

void print(const vector<string>& a)
{
	printf("[ ");
	for (auto e : a) printf("'%s' ", e.c_str());
	printf("]\n");
}

int main()
{
	Solution sln;
	{
		string s = "leetcode";
		vector<string> wordDict = {"leet", "code"};
		print(sln.wordBreak(s, wordDict)); // answer: ["leet code"]
	}
	{
		string s = "catsanddog";
		vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
		print(sln.wordBreak(s, wordDict)); // answer: ["cats and dog", "cat sand dog"]
	}
	{
		string s = "pineapplepenapple";
		vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
		print(sln.wordBreak(s, wordDict)); // answer: [ "pine apple pen apple", "pineapple pen apple", "pine applepen apple" ]
	}
	{
		string s = "catsandog";
		vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
		print(sln.wordBreak(s, wordDict)); // answer: [ ]
	}
	{
		string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
		print(sln.wordBreak(s, wordDict)); // answer: [ ]
	}
	{
		string s = "bb";
		vector<string> wordDict = {"a","b","bbb","bbbb"};
		print(sln.wordBreak(s, wordDict)); // answer: ["b b"]
	}
	return 0;
}
