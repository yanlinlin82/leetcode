// https://leetcode-cn.com/problems/permutations/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() <= 1) {
			res.push_back(nums);
		} else {
			int n = nums.size();
			for (int i = 0; i < n; ++i) {
				int last = nums[i];
				vector<int> a = nums;
				a.erase(a.begin() + i);
				auto sub = permute(a);
				for (auto e : sub) {
					e.push_back(last);
					res.push_back(e);
				}
			}
		}
		return res;
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (auto e : a) {
		printf("  [");
		for (int i = 0; i < e.size(); ++i) {
			if (i > 0) printf(",");
			printf("%d", e[i]);
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3};
		print(s.permute(a));
	}
	return 0;
}
