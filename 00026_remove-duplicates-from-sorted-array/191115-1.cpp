// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = 1;
		for (int i = 1; i < nums.size(); ++i) {
			bool found = false;
			for (int j = 0; j < n; ++j) {
				if (nums[i] == nums[j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				nums[n++] = nums[i];
			}
		}
		return n;
	}
};

void print(vector<int>& nums, int n)
{
	for (int i = 0; i < n; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main()
{
	Solution s;
	vector<int> a1{1,1,2};
	print(a1, s.removeDuplicates(a1));
	vector<int> a2{0,0,1,1,1,2,2,3,3,4};
	print(a2, s.removeDuplicates(a2));
	return 0;
}
