// https://leetcode-cn.com/problems/ransom-note/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> m1, m2;
		for (auto c : ransomNote) ++m1[c];
		for (auto c : magazine) ++m2[c];
		for (auto it = m1.begin(); it != m1.end(); ++it) {
			char c = it->first;
			if (it->second > m2[c]) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.canConstruct("a", "b") << endl; // answer: false
	cout << s.canConstruct("aa", "ab") << endl; // answer: false
	cout << s.canConstruct("aa", "aab") << endl; // answer: true
	return 0;
}
