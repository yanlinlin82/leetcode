// https://leetcode-cn.com/problems/remove-duplicate-letters/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {

	}
};

int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("bcabc") << endl; // answer: "abc"
	cout << s.removeDuplicateLetters("cbacdcbc") << endl; // answer: "acdb"
	return 0;
}
