// https://leetcode-cn.com/problems/shortest-palindrome/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		vector<pair<char, int>> a;
		char last = 0;
		int count = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != last) {
				if (count > 0) a.push_back(make_pair(last, count));
				last = s[i];
				count = 1;
			} else {
				++count;
			}
		}
		if (count > 0) {
			a.push_back(make_pair(last, count));
		}

		int n = a.size();
		for (; n > 1; --n) {
			int i = n / 2 - 1;
			int j = i + 1 + (n % 2);
			for (; i >= 0; --i, ++j) {
				if (a[i].first != a[j].first) break;
				if (i > 0) {
					if (a[i].second != a[j].second) break;
				} else {
					if (a[i].second > a[j].second) break;
				}
			}
			if (i < 0) break;
		}
		string t;
		for (int i = n; i < a.size(); ++i) {
			t = string(a[i].second, a[i].first) + t;
		}
		if (n > 0 && a[0].second < a[n - 1].second) {
			t += string(a[n - 1].second - a[0].second, a[0].first);
		}
		return t + s;
	}
};

int main()
{
	Solution s;
	cout << s.shortestPalindrome("aacecaaa") << endl; // answer: aaacecaaa
	cout << s.shortestPalindrome("abcd") << endl; // answer: dcbabcd
	cout << s.shortestPalindrome("abbacd") << endl; // answer: dcabbacd
	cout << s.shortestPalindrome(string(20000, 'a') + "cd" + string(20000, 'a')) << endl;
	cout << s.shortestPalindrome(string(200000, 'a') + "cd" + string(200000, 'a')) << endl;
	return 0;
}
