// https://leetcode-cn.com/problems/ugly-number-ii/
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		set<long long> a;
		a.insert(1);
		for (int i = 1; i < n; ++i) {
			long long x = *a.begin();
			a.insert(x * 2);
			a.insert(x * 3);
			a.insert(x * 5);
			a.erase(x);
		}
		return (int)*a.begin();
	}
};

int main()
{
	Solution s;
	cout << s.nthUglyNumber(10) << endl; // answer: 12
	return 0;
}
