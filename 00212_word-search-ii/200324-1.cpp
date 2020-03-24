// https://leetcode-cn.com/problems/word-search-ii/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie trie;
		for (auto& w : words) trie.Add(w);
		unordered_set<string> m;
		vector<string> res;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				Search(board, i, j, trie, m, res, "");
			}
		}
		return res;
	}
private:
	class Trie {
	public:
		Trie(): end(false) { }
		~Trie() {
			for (auto it = o.begin(); it != o.end(); ++it) {
				delete it->second;
			}
			o.clear();
		}
		void Add(string s) {
			if (s.empty()) {
				end = true;
			} else {
				char c = s[0];
				auto it = o.find(c);
				Trie* p;
				if (it == o.end()) {
					p = new Trie();
					o[c] = p;
				} else {
					p = it->second;
				}
				p->Add(s.substr(1));
			}
		}
		bool Has(string s) const {
			if (s.empty()) {
				return end;
			} else {
				char c = s[0];
				auto it = o.find(c);
				if (it == o.end()) {
					return false;
				} else {
					return it->second->Has(s.substr(1));
				}
			}
		}
		bool Match(string s) const {
			if (s.empty()) {
				return true;
			} else {
				char c = s[0];
				auto it = o.find(c);
				if (it == o.end()) {
					return false;
				} else {
					return it->second->Match(s.substr(1));
				}
			}
		}
	private:
		bool end;
		unordered_map<char, Trie*> o;
	};
	void Search(vector<vector<char>>& board, int i, int j, const Trie& trie,
			unordered_set<string>& m, vector<string>& res, string s) {
		char c = board[i][j];
		s += c;
		if (!trie.Match(s)) return;
		if (trie.Has(s) && m.find(s) == m.end()) {
			m.insert(s);
			res.push_back(s);
		}
		board[i][j] = '\0';
		if (i > 0 && board[i - 1][j]) Search(board, i - 1, j, trie, m, res, s);
		if (i + 1 < board.size() && board[i + 1][j]) Search(board, i + 1, j, trie, m, res, s);
		if (j > 0 && board[i][j - 1]) Search(board, i, j - 1, trie, m, res, s);
		if (j + 1 < board[i].size() && board[i][j + 1]) Search(board, i, j + 1, trie, m, res, s);
		board[i][j] = c;
	}
};

void print(const vector<string>& a)
{
	cout << "[ "; for (auto& e : a) cout << '"' << e << "\" "; cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<char>> board = {
			{'o','a','a','n'},
			{'e','t','a','e'},
			{'i','h','k','r'},
			{'i','f','l','v'}
		};
		vector<string> words = {"oath","pea","eat","rain"};
		vector<string> a = s.findWords(board, words);
		print(a); // answer: [ "oath" "eat" ]
	}
	{
		vector<vector<char>> board = {
			{'b','b','a','a','b','a'},
			{'b','b','a','b','a','a'},
			{'b','b','b','b','b','b'},
			{'a','a','a','b','a','a'},
			{'a','b','a','a','b','b'}
		};
		vector<string> words = {"abbbababaa"};
		vector<string> a = s.findWords(board, words);
		print(a); // answer: [ "abbbababaa" ]
	}
	return 0;
}
