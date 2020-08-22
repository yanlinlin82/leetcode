// https://leetcode-cn.com/problems/super-ugly-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> idx(primes.size());
		vector<int> a = { 1 };
		for (int i = 1; a.size() < n; ++i) {
			int x = numeric_limits<int>::max();
			int k = -1;
			for (int j = 0; j < primes.size(); ++j) {
				int x2 = a[idx[j]] * primes[j];
				if (x2 < x) {
					x = x2;
					k = j;
				}
			}
			if (x > a.back()) {
				a.push_back(x);
			}
			++idx[k];
			//cout << "x = " << x << ", k = " << k << endl;
			//for (auto e : a) cout << e << " "; cout << endl;
		}
		return a.back();
	}
};

int main()
{
	Solution s;
	{
		vector<int> primes = {2,7,13,19};
		cout << s.nthSuperUglyNumber(12, primes) << endl; // answer: 32
	}
	return 0;
}
