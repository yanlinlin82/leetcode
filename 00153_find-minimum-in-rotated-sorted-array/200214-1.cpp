// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		const int* a = &nums[0];
		return findMin(a, n);
	}
private:
	int findMin(const int* p, int n) {
		if (n == 0) return 0;
		if (n == 1) return *p;
		if (n == 2) return min(*p, *(p+1));
		int a, b;
		int k = n / 2;
		if (p[0] < p[k]) {
			a = p[0];
		} else {
			a = findMin(p, k + 1);
		}
		if (p[k] < p[n - 1]) {
			b = p[k];
		} else {
			b = findMin(p + k, n - k);
		}
		return min(a, b);
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,4,5,1,2};
		printf("%d\n", s.findMin(a)); // answer: 1
	}
	{
		vector<int> a = {4,5,6,7,0,1,2};
		printf("%d\n", s.findMin(a)); // answer: 0
	}
	return 0;
}
