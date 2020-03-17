// https://leetcode-cn.com/problems/isomorphic-strings/
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> o;
		unordered_set<char> x;
		for (int i = 0; i < s.size(); ++i) {
			char c1 = s[i];
			char c2 = t[i];
			auto it = o.find(c1);
			if (it == o.end()) {
				if (x.find(c2) != x.end()) {
					return false;
				}
				o.insert(make_pair(c1, c2));
				x.insert(c2);
			} else {
				if (it->second != c2) {
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isIsomorphic("egg", "add") << endl; // answer: true
	cout << s.isIsomorphic("foo", "bar") << endl; // answer: false
	cout << s.isIsomorphic("paper", "title") << endl; // answer: true
	cout << s.isIsomorphic("ab", "aa") << endl; // answer: false
	return 0;
}
