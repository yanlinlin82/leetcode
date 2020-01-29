// https://leetcode-cn.com/problems/subsets-ii/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<unordered_map<int,pair<int,int>>> cnt; // [ num => { # true, # false } ]
		vector<bool> b;
		subsetsWithDup(res, nums, cnt, b);
		return res;
	}
private:
	void subsetsWithDup(vector<vector<int>>& res, const vector<int>& nums,
			vector<unordered_map<int,pair<int,int>>>& cnt, vector<bool> b) {
		if (b.size() < nums.size()) {
			for (int i = 0; i < 2; ++i) {
				b.push_back(i > 0);
				subsetsWithDup(res, nums, cnt, b);
				b.pop_back();
			}
		} else {
			vector<int> a;
			unordered_map<int,pair<int,int>> c;
			for (size_t i = 0; i < b.size(); ++i) {
				int x = nums[i];
				if (b[i]) {
					a.push_back(x);
					++c[x].first;
				} else {
					++c[x].second;
				}
			}
			bool found = false;
			for (size_t i = 0; i < cnt.size(); ++i) {
				bool match = true;
				for (auto it = c.begin(); it != c.end(); ++it) {
					int x = it->first;
					if (cnt[i][x].first != it->second.first ||
							cnt[i][x].second != it->second.second) {
						match = false;
						break;
					}
				}
				if (match) { found = true; break; }
			}
			if (!found) {
				res.push_back(a);
				cnt.push_back(c);
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (size_t i = 0; i < a.size(); ++i) {
		printf("  [");
		for (size_t j = 0; j < a[i].size(); ++j) {
			printf("%s%d", (j==0?"":","), a[i][j]);
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,2};
		print(s.subsetsWithDup(a)); // answer: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
	}
	return 0;
}
