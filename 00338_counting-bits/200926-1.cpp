// https://leetcode-cn.com/problems/counting-bits/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> a(num + 1);
		int w = 1, i = 1;
		while (i <= num) {
			for (i = w; i < 2 * w && i <= num; ++i) {
				a[i] = a[i - w] + 1;
			}
			w += w;
		}
		return a;
	}
};

void print(const vector<int>& a) {
	for (auto e : a) cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		auto a = s.countBits(2);
		print(a); // answer: [0,1,1]
	}
	{
		auto a = s.countBits(5);
		print(a); // answer: [0,1,1,2,1,2]
	}
	return 0;
}
