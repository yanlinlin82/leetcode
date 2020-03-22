// https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary(): end(false) {
	}

	~WordDictionary()
	{
		for (auto it = m.begin(); it != m.end(); ++it) {
			delete it->second;
		}
		m.clear();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		if (word.empty()) {
			end = true;
		} else {
			char c = word[0];
			auto it = m.find(c);
			WordDictionary* p;
			if (it == m.end()) {
				p = new WordDictionary();
				m[c] = p;
			} else {
				p = it->second;
			}
			p->addWord(word.substr(1));
		}
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		if (word.empty()) return end;
		char c = word[0];
		if (c == '.') {
			for (auto it = m.begin(); it != m.end(); ++it) {
				if (it->second->search(word.substr(1))) {
					return true;
				}
			}
			return false;
		} else {
			auto it = m.find(c);
			if (it == m.end()) return false;
			return it->second->search(word.substr(1));
		}
	}

private:
	bool end;
	unordered_map<char, WordDictionary*> m;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
	WordDictionary obj;
	obj.addWord("bad");
	obj.addWord("dad");
	obj.addWord("mad");
	cout << obj.search("pad") << endl; // -> false
	cout << obj.search("bad") << endl; // -> true
	cout << obj.search(".ad") << endl; // -> true
	cout << obj.search("b..") << endl; // -> true
	return 0;
}
