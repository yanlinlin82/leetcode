// https://leetcode-cn.com/problems/happy-number/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> s;
		while (n != 1) {
			s.insert(n);
			int x = 0;
			while (n > 0) {
				x += (n % 10) * (n % 10);
				n /= 10;
			}
			if (s.find(x) != s.end()) return false;
			n = x;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(19) << endl; // answer: true
	cout << s.isHappy(2) << endl; // answer: 2
	return 0;
}
