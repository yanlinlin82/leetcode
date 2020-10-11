// https://leetcode-cn.com/problems/reverse-string/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int n = s.size();
		for (int i = 0; i < n / 2; ++i) {
			swap(s[i], s[n - i - 1]);
		}
	}
};

void print(const vector<char>& a)
{
	for (auto c : a) cout << c << ' ';
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<char> a = {'h','e','l','l','o'};
		print(a);
		s.reverseString(a);
		print(a); // answer: ['o','l','l','e','h']
	}
	{
		vector<char> a = {'H','a','n','n','a','h'};
		print(a);
		s.reverseString(a);
		print(a); // answer: ['h','a','n','n','a','H']
	}
	return 0;
}
