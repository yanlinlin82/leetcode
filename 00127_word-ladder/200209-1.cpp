// https://leetcode-cn.com/problems/word-ladder/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
		if (end < 0) return 0;
		vector<int> v(n);
		v[start] = 1;
		unordered_set<int> curr{start};
		while (!curr.empty() && curr.find(end) == curr.end()) {
			unordered_set<int> next;
			for (auto i : curr) {
				for (int j = 0; j < n; ++j) {
					if (a[i][j] && v[j] == 0) {
						next.insert(j);
						v[j] = v[i] + 1;
					}
				}
			}
			curr = next;
		}
		return v[end];

	}
};

int main()
{
	Solution s;
	{
		string beginWord = "hit";
		string endWord = "cog";
		vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
		printf("%d\n", s.ladderLength(beginWord, endWord, wordList)); // answer: 5
	}
	{
		string beginWord = "hit";
		string endWord = "cog";
		vector<string> wordList = {"hot","dot","dog","lot","log"};
		printf("%d\n", s.ladderLength(beginWord, endWord, wordList)); // answer: 0
	}
	return 0;
}
