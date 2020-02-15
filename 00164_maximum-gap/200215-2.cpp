// https://leetcode-cn.com/problems/maximum-gap/
// 基数排序，时间复杂度O(n+b)
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		//for (auto e : nums) printf("%d ", e); printf("\n");
		radix_sort(nums);
		//for (auto e : nums) printf("%d ", e); printf("\n");
		int maxGap = nums[1] - nums[0];
		for (int i = 2; i < nums.size(); ++i) {
			int gap = nums[i] - nums[i - 1];
			if (maxGap < gap) maxGap = gap;
		}
		return maxGap;
	}
private:
	void radix_sort(vector<int>& nums) {
		int maxVal = *max_element(nums.begin(), nums.end());
		int exp = 1;
		int base = 10;
		while (maxVal / exp > 0) {
			vector<int> count(base, 0);
			for (int i = 0; i < nums.size(); ++i) {
				++count[(nums[i] / exp) % base];
			}
			partial_sum(count.begin(), count.end(), count.begin());
			vector<int> aux(nums.size());
			for (int i = nums.size() - 1; i >= 0; --i) {
				aux[--count[(nums[i] / exp) % base]] = nums[i];
			}
			nums = aux;
			exp *= base;
		}
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,6,9,1};
		printf("%d\n", s.maximumGap(a)); // answer: 3, between 3 and 6, or 6 and 9
	}
	{
		vector<int> a = {10};
		printf("%d\n", s.maximumGap(a)); // answer: 0, vector size < 2
	}
	{
		vector<int> a = {1,3,2,6};
		printf("%d\n", s.maximumGap(a)); // answer: 3, between 3 and 6
	}
	{
		vector<int> a = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
		printf("%d\n", s.maximumGap(a)); // answer:
	}
	return 0;
}
