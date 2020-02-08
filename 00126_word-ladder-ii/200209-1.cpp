// https://leetcode-cn.com/problems/word-ladder-ii/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<string> w = wordList; w.push_back(beginWord);
		int m = beginWord.size();
		int n = w.size();
		vector<vector<bool>> a(n); for (int i = 0; i < n; ++i) a[i].resize(n);
		int start = -1, end = -1;
		for (int i = 0; i < n; ++i) {
			if (start < 0 && beginWord == w[i]) start = i;
			if (end < 0 && endWord == w[i]) end = i;
			for (int j = i + 1; j < n; ++j) {
				int d = 0; for (int k = 0; k < m; ++k) d += (w[i][k] != w[j][k]);
				a[i][j] = a[j][i] = (d == 1);
			}
		}
		vector<vector<string>> res;
		if (end >= 0) {
			vector<pair<int,vector<vector<int>>>> v(n);
			v[start] = make_pair(1, vector<vector<int>>{{start}});
			unordered_set<int> curr{start};
			while (!curr.empty() && curr.find(end) == curr.end()) {
				unordered_set<int> next;
				for (auto i : curr) {
					for (int j = 0; j < n; ++j) {
						if (a[i][j] && (v[j].first == 0 || v[j].first == v[i].first + 1)) {
							next.insert(j);
							v[j].first = v[i].first + 1;
							for (int k = 0; k < v[i].second.size(); ++k) {
								vector<int> p = v[i].second[k];
								p.push_back(j);
								v[j].second.push_back(p);
							}
						}
					}
				}
				curr = next;
			}
			for (auto& e : v[end].second) {
				vector<string> a;
				for (auto i : e) a.push_back(w[i]);
				res.push_back(a);
			}
		}
		return res;
	}
};

void print(const vector<vector<string>>& a)
{
	printf("[\n");
	for (const auto& r : a) {
		printf("  [");
		for (size_t i = 0; i < r.size(); ++i) {
			printf("%s'%s'", (i>0?",":""), r[i].c_str());
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		string beginWord = "hit";
		string endWord = "cog";
		vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
		print(s.findLadders(beginWord, endWord, wordList)); // answer: [ ["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"] ]
	}
	{
		string beginWord = "hit";
		string endWord = "cog";
		vector<string> wordList = {"hot","dot","dog","lot","log"};
		print(s.findLadders(beginWord, endWord, wordList)); // answer: [ ]
	}
	return 0;
}
