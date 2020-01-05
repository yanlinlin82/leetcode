// https://leetcode-cn.com/problems/permutation-sequence/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		const char* S = "123456789";
		std::string s(S, S + n);
		//printf("[0] %s\n", s.c_str());
		for (int t = 1; t < k; ++t) {
			int i = n - 2;
			while (i >= 0 && s[i] > s[i + 1]) --i; // find first number that less than its right number
			char c = s[i];
			for (int j = i + 1; j < n; ++j) { // swap it with the minimum bigger one
				if (j + 1 >= n || s[j + 1] < c) {
					s[i] = s[j];
					s[j] = c;
					break;
				}
			}
			for (int j = 1; j < (n - i + 1) / 2; ++j) { // reverse order of whole right sequence
				c = s[i + j];
				s[i + j] = s[n - j];
				s[n - j] = c;
			}
			//printf("[%d] %s\n", t, s.c_str());
		}
		return s;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.getPermutation(3, 3).c_str()); // answer: "213"
	printf("%s\n", s.getPermutation(4, 9).c_str()); // answer: "2314"
	return 0;
}
