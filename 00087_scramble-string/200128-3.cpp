// https://leetcode-cn.com/problems/scramble-string/
// 第三次尝试：挑战失败，因为未考虑s1中也可能存在重复字符
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		unordered_map<char, int> index;
		for (int i = 0; i < s1.size(); ++i) {
			index[s1[i]] = i;
		}
		vector<int> a;
		unordered_map<char, int> flag;
		for (int i = 0; i < s2.size(); ++i) {
			if (index.find(s2[i]) == index.end()) return false;
			if (flag.find(s2[i]) != flag.end()) return false;
			a.push_back(index[s2[i]]);
			flag[s2[i]] = 1;
		}
		return isScramble(a, 0, a.size() - 1);
	}
private:
	bool isScramble(const vector<int>& a, int i, int j) {
		if (j - i < 2) return true;
		for (int k = i + 1; k <= j - 1; ++k) {
			if (isPartition(a, i, j, k)) {
				if (isScramble(a, i, k - 1) && isScramble(a, k + 1, j)) {
					return true;
				}
			}
		}
		return false;
	}
	bool isPartition(const vector<int>& a, int i, int j, int k) {
		if (a[i] < a[k] && a[j] < a[k]) return false;
		if (a[i] > a[k] && a[j] > a[k]) return false;
		if (a[i] < a[k]) {
			for (int l = i + 1; l < k; ++l) {
				if (a[l] > a[k]) return false;
			}
			for (int l = k + 1; l < j; ++l) {
				if (a[l] < a[k]) return false;
			}
		} else {
			for (int l = i + 1; l < k; ++l) {
				if (a[l] < a[k]) return false;
			}
			for (int l = k + 1; l < j; ++l) {
				if (a[l] > a[k]) return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isScramble("great", "rgeat")); // answer: true
	printf("%d\n", s.isScramble("abcde", "caebd")); // answer: false
	printf("%d\n", s.isScramble("ab", "ab")); // answer: true
	printf("%d\n", s.isScramble("ab", "ba")); // answer: true
	printf("%d\n", s.isScramble("abc", "abc")); // answer: true
	printf("%d\n", s.isScramble("abc", "cba")); // answer: true
	printf("%d\n", s.isScramble("abc", "bca")); // answer: false
	printf("%d\n", s.isScramble("abc", "acb")); // answer: false
	printf("%d\n", s.isScramble("abc", "bac")); // answer: false
	printf("%d\n", s.isScramble("abc", "cab")); // answer: false
	printf("%d\n", s.isScramble("a", "b")); // answer: false
	return 0;
}
