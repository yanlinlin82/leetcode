// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int n = s.size();
		int i = 0, j = n - 1;
		while (i < j) {
			if (isVowel(s[i]) && isVowel(s[j])) {
				swap(s[i++], s[j--]);
			} else {
				if (!isVowel(s[i])) ++i;
				if (!isVowel(s[j])) --j;
			}
		}
		return s;
	}
private:
	bool isVowel(char c) {
		switch (c) {
		case 'A': case 'a':
		case 'E': case 'e':
		case 'I': case 'i':
		case 'O': case 'o':
		case 'U': case 'u':
			return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.reverseVowels("hello") << endl; // answer: "holle"
	cout << s.reverseVowels("leetcode") << endl; // answer: "leotcede"
	return 0;
}
