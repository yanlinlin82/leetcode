// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (words.empty()) return res;
		int n = s.size();
		int wordCount = words.size();
		int wordSize = words[0].size();
		unordered_map<string, int> wid; // word => id
		unordered_map<int, int> wc; // id => count
		for (int i = 0; i < words.size(); ++i) {
			if (wid.find(words[i]) == wid.end()) {
				wid[words[i]] = i;
			}
			wc[wid[words[i]]]++;
		}
		unordered_map<int, int> sid; // pos => id
		for (int pos = 0; pos <= n - wordSize; ++pos) {
			string w = s.substr(pos, wordSize);
			auto it = wid.find(w);
			if (it == wid.end()) {
				sid[pos] = -1;
			} else {
				sid[pos] = it->second;
			}
		}
		for (int offset = 0; offset < wordSize; ++offset) {
			for (int pos = offset; pos < n; pos += wordSize) {
				unordered_map<int, int> counter;
				bool bad = false;
				int i = 0;
				for (; i < wordCount; ++i) {
					int pos2 = pos + i * wordSize;
					if (pos2 > n - wordSize) break;
					int k = sid[pos2];
					if (k == -1 || counter[k] >= wc[k]) {
						bad = true;
						break;
					}
					counter[k]++;
				}
				if (!bad && i == wordCount) {
					res.push_back(pos);
				}
			}
		}
		return res;
	}
};

void print(vector<int> a)
{
	for (auto& e : a) {
		printf("%d ", e);
	}
	printf("\n");
}

int main()
{
	Solution s;
	{
		vector<string> words{"foo","bar"};
		print(s.findSubstring("barfoothefoobarman", words)); // answer: [0, 9]
	}
	{
		vector<string> words{"word","good","best","word"};
		print(s.findSubstring("wordgoodgoodgoodbestword", words)); // answer: []
	}
	{
		vector<string> words{"word","good","best","good"};
		print(s.findSubstring("wordgoodgoodgoodbestword", words)); // answer: [8]
	}
	return 0;
}
