// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int flags[256] = { };
		int start = 0;
		int longest = 0;
		for (int i = 0; i < s.size(); ++i) {
			unsigned char c = static_cast<unsigned char>(s[i]);
			if (flags[c] == 0) { // not found
				int size = i + 1 - start;
				if (longest < size) {
					longest = size;
				}
			} else { // found
				while (start < flags[c]) {
					unsigned char c2 = static_cast<unsigned char>(s[start++]);
					flags[c2] = false;
				}
			}
			flags[c] = i + 1;
		}
		return longest;
    }
};

int main()
{
	Solution s;
	printf("%d\n", s.lengthOfLongestSubstring("abcabcbb")); // answer: 3 ("abc")
	printf("%d\n", s.lengthOfLongestSubstring("bbbbb"));    // answer: 1 ("b")
	printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));   // answer: 3 ("wke")
	return 0;
}
