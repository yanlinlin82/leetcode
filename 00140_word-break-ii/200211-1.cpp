// https://leetcode-cn.com/problems/word-break-ii/
// 挑战失败：超出内存限制
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		Node dict;
		for (auto w : wordDict) init(dict, w.c_str());
		vector<vector<string>> m(s.size() + 1);
		m[0].push_back("");
		for (int i = 0; i < s.size(); ++i) {
			if (m[i].empty()) continue;
			vector<int> a;
			query(s.c_str() + i, dict, 0, a);
			for (int k = 0; k < m[i].size(); ++k) {
				string t = m[i][k];
				if (!t.empty()) t += " ";
				for (int j = 0; j < a.size(); ++j) {
					m[i + a[j]].push_back(t + s.substr(i, a[j]));
				}
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
	return 0;
}
