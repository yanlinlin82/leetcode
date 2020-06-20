// https://leetcode-cn.com/problems/h-index/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int n = citations.size();
		for (int i = 0; i < n; ++i) {
			if (citations[i] >= (n - i)) {
				return n - i;
			}
		}
		return 0;
	}
};

int main()
{
	Solution s;
	{
		vector<int> citations = {3,0,6,1,5};
		cout << s.hIndex(citations) << endl; // answer: 3
	}
	return 0;
}
