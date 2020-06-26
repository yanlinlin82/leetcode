// https://leetcode-cn.com/problems/first-bad-version/
#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version) {
	return (version >= 4);
}

class Solution {
public:
	int firstBadVersion(int n) {
		int i = 1, j = n;
		while (i < j) {
			int k = i + (j - i) / 2;
			if (isBadVersion(k)) {
				j = k;
			} else {
				i = k + 1;
			}
		}
		return i;
	}
};

int main()
{
	Solution s;
	cout << s.firstBadVersion(5) << endl; // answer: 4
	return 0;
}
