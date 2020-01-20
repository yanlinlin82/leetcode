// https://leetcode-cn.com/problems/subsets/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> a;
		vector<bool> value(nums.size());
		doSubsets(a, nums, value, 0);
		return a;
	}
private:
	void doSubsets(vector<vector<int>>& results, vector<int>& nums, vector<bool>& value, int i) {
		if (i >= value.size()) {
			vector<int> a;
			for (int k = 0; k < value.size(); ++k) {
				if (value[k]) {
					a.push_back(nums[k]);
				}
			}
			results.push_back(a);
		} else {
			for (int k = 0; k <= 1; ++k) {
				value[i] = (k != 0);
				doSubsets(results, nums, value, i + 1);
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (auto e : a) {
		printf("  [");
		for (auto e2 : e) {
			printf(" %d", e2);
		}
		printf(" ]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3};
		print(s.subsets(a)); // answer: [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
	}
	return 0;
}
