// https://leetcode-cn.com/problems/maximum-product-subarray/
// 挑战失败：超出时间限制
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		bool first = true;
		int max = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int prod = nums[i];
				for (int k = i + 1; k <= j; ++k) {
					prod *= nums[k];
				}
				if (first || max < prod) {
					max = prod;
					first = false;
				}
			}
		}
		return max;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,3,-2,4};
		printf("%d\n", s.maxProduct(a)); // answer: 6
	}
	{
		vector<int> a = {-2,0,-1};
		printf("%d\n", s.maxProduct(a)); // answer: 0
	}
	return 0;
}
