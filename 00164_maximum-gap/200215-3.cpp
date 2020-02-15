// https://leetcode-cn.com/problems/maximum-gap/
// 桶排序
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		int min = *min_element(nums.begin(), nums.end());
		int max = *max_element(nums.begin(), nums.end());
		int bucketSize = std::max(1, (max - min) / (n - 1));
		int bucketNum = (max - min) / bucketSize + 1;
		vector<Node> bucket(bucketNum);
		for (int x : nums) {
			int index = (x - min) / bucketSize;
			bucket[index].used = true;
			bucket[index].min = std::min(x, bucket[index].min);
			bucket[index].max = std::max(x, bucket[index].max);
		}
		int maxGap = 0, prevMax = min;
		for (auto b : bucket) {
			if (!b.used) continue;
			maxGap = std::max(maxGap, b.min - prevMax);
			prevMax = b.max;
		}
		return maxGap;
	}
private:
	struct Node {
		bool used = false;
		int min = numeric_limits<int>::max();
		int max = numeric_limits<int>::min();
	};
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
