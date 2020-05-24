// https://leetcode-cn.com/problems/product-of-array-except-self/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				a[i] = nums[i];
			} else {
				a[i] = a[i - 1] * nums[i];
			}
		}
		vector<int> b(n);
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				b[i] = nums[i];
			} else {
				b[i] = b[i + 1] * nums[i];
			}
		}
		vector<int> c(n);
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				c[i] = b[i + 1];
			} else if (i == n - 1) {
				c[i] = a[i - 1];
			} else {
				c[i] = a[i - 1] * b[i + 1];
			}
		}
		return c;
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
