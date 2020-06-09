// https://leetcode-cn.com/problems/valid-anagram/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int x[256] = { };
		for (auto c : s) {
			++x[static_cast<unsigned char>(c)];
		}
		for (auto c : t) {
			--x[static_cast<unsigned char>(c)];
		}
		for (int i = 0; i < 256; ++i) {
			if (x[i] != 0) return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isAnagram("anagram", "nagaram") << endl; // answer: true
	cout << s.isAnagram("rat", "car") << endl; // answer: false
	return 0;
}
