// https://leetcode-cn.com/problems/permutations-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> res;
		if (n <= 1) {
			res.push_back(nums);
		} else {
			for (int i = 0; i < n; ++i) {
				int last = nums[i];
				vector<int> a = nums;
				a.erase(a.begin() + i);
				auto sub = permuteUnique(a);
				for (auto e : sub) {
					e.push_back(last);
					appendUnique(res, e);
				}
			}
		}
		return res;
	}
private:
	void appendUnique(vector<vector<int>>& res, vector<int>& a) {
		for (int i = 0; i < res.size(); ++i) {
			if (res[i] == a) {
				return;
			}
		}
		res.push_back(a);
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
		vector<int> a = {1,1,2};
		print(s.permuteUnique(a));
	}
	{
		vector<int> a = {2,2,1,1};
		print(s.permuteUnique(a));
	}
	return 0;
}
