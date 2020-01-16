// https://leetcode-cn.com/problems/sort-colors/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return;
		for (int i = 0, j = n - 1, k = i; k <= j;) {
			int current = nums[k];
			if (current == 0) {
				if (k > i) {
					nums[k] = nums[i];
					nums[i] = 0;
				}
				++i; ++k;
			} else if (current == 2) {
				if (k < j) {
					nums[k] = nums[j];
					nums[j] = 2;
				}
				--j;
			} else {
				++k;
			}
		}
	}
};

void print(const vector<int>& a)
{
	printf("[");
	for (int i = 0; i < a.size(); ++i) {
		printf("%s%d", (i==0?"":","), a[i]);
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {2,0,2,1,1,0};
		s.sortColors(a);
		print(a); // answer: [0,0,1,1,2,2]
	}
	{
		vector<int> a = {1,2,0};
		s.sortColors(a);
		print(a); // answer: [0,1,2]
	}
	return 0;
}
