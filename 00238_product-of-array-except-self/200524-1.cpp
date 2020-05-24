// https://leetcode-cn.com/problems/product-of-array-except-self/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> a(nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			a[i] = 1;
		}
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i != j) {
					a[i] *= nums[j];
				}
			}
		}
		return a;
	}
};

void print(vector<int>&& a)
{
	for (auto e : a) cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,4};
		print(s.productExceptSelf(a));
	}
	return 0;
}
