// https://leetcode-cn.com/problems/count-primes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> crossed(n);
		int count = 0;
		for (int i = 2; i < n; ++i) {
			if (!crossed[i]) {
				++count;
				for (int j = i + i; j < n; j += i) {
					crossed[j] = true;
				}
			}
		}
		return count;
	}
};

int main()
{
	Solution s;
	cout << s.countPrimes(10) << endl; // answer: 4
	return 0;
}
