// https://leetcode-cn.com/problems/longest-consecutive-sequence/
#include <cstdio>
#include <vector>
#include <memory>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		unordered_map<int, pair<int, int>> r;
		int longest = 1;
		for (int i = 0; i < n; ++i) {
			int v = nums[i];
			auto p = r.find(v);
			if (p != r.end()) continue; // skip if existed

			auto p1 = r.find(v - 1);
			int min = (p1 == r.end() ? v : p1->second.first);

			auto p2 = r.find(v + 1);
			int max = (p2 == r.end() ? v : p2->second.second);

			r[v] = make_pair(min, max);
			if (min < v) r[min] = r[v];
			if (max > v) r[max] = r[v];

			int range = max - min + 1;
			if (longest < range) {
				longest = range;
			}
		}
		return longest;
	}
};

int main()
{
	//vector<int> nums = { 0, 0 };                 // answer = 1
	//vector<int> nums = { 100, 4, 200, 1, 3, 2 }; // answer = 4
	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};      // answer = 9
	Solution s;
	printf("%d\n", s.longestConsecutive(nums));
	return 0;
}
