// https://leetcode-cn.com/problems/first-missing-positive/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		ranges.clear();
		for (int i = 0; i < nums.size(); ++i) {
			add(nums[i]);
			//printf("%d: ", nums[i]); for (auto e : ranges) {printf("%d,%d ", e.first, e.second);};printf("\n");
		}
		return (ranges.empty() || ranges[0].first != 1) ? 1 : ranges[0].second + 1;
	}
private:
	void add(int x) {
		if (x <= 0) return;
		for (int i = 0; i < ranges.size(); ++i) {
			int a = ranges[i].first;
			int b = ranges[i].second;
			if (x < a - 1) {
				ranges.insert(ranges.begin() + i, make_pair(x, x));
				return;
			} else if (x == a - 1) {
				ranges[i].first = x;
				return;
			} else if (x >= a && x <= b) {
				return;
			} else if (x == b + 1) {
				if (i + 1 < ranges.size() && ranges[i + 1].first == x + 1) {
					ranges[i].second = ranges[i + 1].second;
					ranges.erase(ranges.begin() + i + 1);
				} else {
					ranges[i].second = x;
				}
				return;
			} else {
				continue;
			}
		}
		ranges.push_back(make_pair(x, x));
	}
	vector<pair<int,int>> ranges;
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,0};
		printf("%d\n", s.firstMissingPositive(a)); // answer: 3
	}
	{
		vector<int> a = {3,4,-1,1};
		printf("%d\n", s.firstMissingPositive(a)); // answer: 2
	}
	{
		vector<int> a = {7,8,9,11,12};
		printf("%d\n", s.firstMissingPositive(a)); // answer: 1
	}
	{
		vector<int> a = {2,1};
		printf("%d\n", s.firstMissingPositive(a)); // answer: 3
	}
	return 0;
}
