// https://leetcode-cn.com/problems/h-index-ii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
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
		vector<int> citations = {0,1,3,5,6};
		cout << s.hIndex(citations) << endl; // answer: 3
	}
	return 0;
}

