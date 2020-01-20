// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int last = nums[0];
		int dup = 0;
		int i = 1;
		for (int j = 1; j < nums.size();) {
			if (nums[j] != last) {
				dup = 0;
				last = nums[j];
			} else {
				++dup;
			}
			if (dup >= 2) {
				++j;
			} else if (j > i) {
				nums[i++] = nums[j++];
			} else {
				++i; ++j;
			}
		}
		return i;
	}
};

void print(int n, const vector<int>& a)
{
	printf("%d [", n);
	for (int i = 0; i < n; ++i) { printf(" %d", a[i]); }
	printf(" ]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,1,1,2,2,3};
		int n = s.removeDuplicates(a);
		print(n, a); // answer: 5, [1, 1, 2, 2, 3]
	}
	{
		vector<int> a = {0,0,1,1,1,1,2,3,3};
		int n = s.removeDuplicates(a);
		print(n, a); // answer: 7, [0, 0, 1, 1, 2, 3, 3]
	}
	return 0;
}
