// https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<int> lengths(n);
		for (int i = 0; i < n; ++i) {
			lengths[i] = words[i].size();
		}
		vector<unordered_set<char>> m(n);
		for (int i = 0; i < n; ++i) {
			for (auto c : words[i]) {
				m[i].insert(c);
			}
		}
		int maxProd = 0;
		for (int i = 0; i + 1 < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				bool found = false;
				for (auto c : m[i]) {
					if (m[j].find(c) != m[j].end()) {
						found = true;
						break;
					}
				}
				if (!found) {
					int prod = lengths[i] * lengths[j];
					if (maxProd < prod) {
						maxProd = prod;
					}
				}
			}
		}
		return maxProd;
	}
};

int main()
{
	Solution s;
	{
		vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
		cout << s.maxProduct(words) << endl; // answer: 16
	}
	{
		vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};
		cout << s.maxProduct(words) << endl; // answer: 4
	}
	{
		vector<string> words = {"a","aa","aaa","aaaa"};
		cout << s.maxProduct(words) << endl; // answer: 0
	}
	return 0;
}
