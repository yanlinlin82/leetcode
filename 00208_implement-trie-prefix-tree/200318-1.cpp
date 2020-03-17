// https://leetcode-cn.com/problems/implement-trie-prefix-tree/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): end_(false) { }

	~Trie() {
		for (auto it = children_.begin(); it != children_.end(); ++it) {
			delete it->second;
		}
		children_.clear();
	}

    /** Inserts a word into the trie. */
    void insert(string word) {
		if (word.empty()) {
			end_ = true;
		} else {
			Trie* t = NULL;
			auto it = children_.find(word[0]);
			if (it == children_.end()) {
				t = new Trie();
				children_[word[0]] = t;
			} else {
				t = it->second;
			}
			t->insert(word.substr(1));
		}
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		if (word.empty()) {
			return end_;
		} else {
			auto it = children_.find(word[0]);
			if (it == children_.end()) return false;
			return it->second->search(word.substr(1));
		}
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		if (prefix.empty()) {
			return true;
		} else {
			auto it = children_.find(prefix[0]);
			if (it == children_.end()) return false;
			return it->second->startsWith(prefix.substr(1));
		}
    }
private:
	bool end_;
	unordered_map<char, Trie*> children_;
};

void print(bool b)
{
	printf("%s\n", (b ? "true" : "false"));
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
	{
		cout << "=======" << endl;
		Trie trie;
		trie.insert("apple");
		print(trie.search("apple"));   // 返回 true
		print(trie.search("app"));     // 返回 false
		print(trie.startsWith("app")); // 返回 true
		trie.insert("app");   
		print(trie.search("app"));     // 返回 true
	}
	{
		cout << "=======" << endl;
		Trie trie;
		trie.insert("app");
		trie.insert("apple");
		trie.insert("beer");
		trie.insert("add");
		trie.insert("jam");
		trie.insert("rental");
		print(trie.search("apps"));         // answer: false
		print(trie.search("app"));          // answer: true
		print(trie.search("ad"));           // answer: false
		print(trie.search("applepie"));     // answer: false
		print(trie.search("rest"));         // answer: false
		print(trie.search("jan"));          // answer: false
		print(trie.search("rent"));         // answer: false
		print(trie.search("beer"));         // answer: true
		print(trie.search("jam"));          // answer: true
		print(trie.startsWith("apps"));     // answer: false
		print(trie.startsWith("app"));      // answer: true
		print(trie.startsWith("ad"));       // answer: true
		print(trie.startsWith("applepie")); // answer: false
		print(trie.startsWith("rest"));     // answer: false
		print(trie.startsWith("jan"));      // answer: false
		print(trie.startsWith("rent"));     // answer: true
		print(trie.startsWith("beer"));     // answer: true
		print(trie.startsWith("jam"));      // answer: true
	}
	return 0;
}
