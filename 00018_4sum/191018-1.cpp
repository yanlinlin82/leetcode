// https://leetcode-cn.com/problems/4sum/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> r;
		for (int a = 0; a + 3 < nums.size(); ++a) {
			for (int b = a + 1; b < nums.size(); ++b) {
				for (int c = b + 1; c < nums.size(); ++c) {
					for (int d = c + 1; d < nums.size(); ++d) {
						if (nums[a] + nums[b] + nums[c] + nums[d] == target) {
							vector<int> v{nums[a], nums[b], nums[c], nums[d]};
							sort(v.begin(), v.end());
							bool found = false;
							for (int i = 0; i < r.size(); ++i) {
								if (r[i] == v) {
									found = true;
									break;
								}
							}
							if (!found) {
								r.push_back(v);
							}
						}
					}
				}
			}
		}
		return r;
	}
};

void print(const vector<vector<int>>& r)
{
	printf("[");
	for (int i = 0; i < r.size(); ++i) {
		printf(" [");
		for (int j = 0; j < r[i].size(); ++j) {
			printf(" %d", r[i][j]);
		}
		printf(" ]");
	}
	printf(" ]\n");
}

int main() {
	Solution s;
	vector<int> nums{1, 0, -1, 0, -2, 2};
	int target = 0;
	print(s.fourSum(nums, target)); // answer:
	return 0;
}
