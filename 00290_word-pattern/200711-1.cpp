// https://leetcode-cn.com/problems/word-pattern/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words = split(str);
		if (pattern.size() != words.size()) {
			return false;
		}
		unordered_map<char, string> m;
		unordered_set<string> m2;
		for (int i = 0; i < pattern.size(); ++i) {
			char c = pattern[i];
			string w = words[i];
			if (m.find(c) == m.end()) {
				if (m2.find(w) != m2.end()) return false;
				m[c] = w;
				m2.insert(w);
			} else {
				if (m[c] != w) return false;
			}
		}
		return true;
	}
private:
	vector<string> split(string str) {
		vector<string> words;
		string s;
		for (auto c : str) {
			if (c == ' ') {
				if (!s.empty()) words.push_back(s);
				s.clear();
			} else {
				s += c;
			}
		}
		if (!s.empty()) words.push_back(s);
		return words;
	}
};

int main() {
	Solution s;
	cout << s.wordPattern("abba", "dog cat cat dog") << endl; // answer: true
	cout << s.wordPattern("abba", "dog cat cat fish") << endl; // answer: false
	cout << s.wordPattern("aaaa", "dog cat cat dog") << endl; // answer: false
	cout << s.wordPattern("abba", "dog dog dog dog") << endl; // answer: false
	cout << s.wordPattern("aaa", "aa aa aa aa") << endl; // answer: false
	cout << s.wordPattern("a", "a") << endl; // answer: true
	return 0;
}
