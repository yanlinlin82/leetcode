// https://leetcode-cn.com/problems/perfect-squares/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> a(n + 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int k = i + j * j;
				if (k > n) break;
				if (a[k] == 0 || a[k] > a[i] + 1) {
					a[k] = a[i] + 1;
				}
			}
		}
		return a[n];
	}
};

int main()
{
	Solution s;
	cout << s.numSquares(12) << endl; // answer: 3
	cout << s.numSquares(13) << endl; // answer: 2
	cout << s.numSquares(7168) << endl; // answer: 4
	cout << s.numSquares(1) << endl; // answer: 1
	return 0;
}
