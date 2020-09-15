// https://leetcode-cn.com/problems/wiggle-sort-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
	}
};

void print(const vector<int>& a)
{
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {1, 5, 1, 1, 6, 4};
		s.wiggleSort(a);
		print(a); // answer maybe: [1, 4, 1, 5, 1, 6]
	}
	{
		vector<int> a = {1, 3, 2, 2, 3, 1};
		s.wiggleSort(a);
		print(a); // answer maybe: [2, 3, 1, 3, 1, 2]
	}
	return 0;
}
