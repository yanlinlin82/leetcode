// https://leetcode-cn.com/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0, n = nums.size();
		while (i < n) {
			if (nums[i] == 0) {
				++i;
			} else {
				if (i != j) {
					nums[j] = nums[i];
				}
				++i;
				++j;
			}
		}
		while (j < n) {
			nums[j++] = 0;
		}
	}
};

void print(const vector<int>& a)
{
	cout << "[ ";
	for (auto e : a) cout << e << " ";
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {0,1,0,3,12};
		print(a);
		s.moveZeroes(a);
		print(a);
	}
	{
		vector<int> a = {1};
		print(a);
		s.moveZeroes(a);
		print(a);
	}
	return 0;
}
