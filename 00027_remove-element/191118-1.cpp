// https://leetcode-cn.com/problems/remove-element/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int n = nums.size();
		int i = 0;
		int j = n - 1;
		while (i < j) {
			if (nums[j] == val) {
				--j;
				--n;
			} else if (nums[i] == val) {
				nums[i] = nums[j];
				++i;
				--j;
				--n;
			} else {
				++i;
			}
		}
		if (nums[i] == val) {
			--n;
		}
		return n;
	}
};

void print(int n, vector<int>& a)
{
	printf("[%d] ", n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	Solution s;
	vector<int> a1{3,2,2,3};
	print(s.removeElement(a1, 3), a1); // answer: 2
	vector<int> a2{0,1,2,2,3,0,4,2};
	print(s.removeElement(a2, 2), a2); // answer: 5
	vector<int> a3{1};
	print(s.removeElement(a3, 1), a3); // answer: 0
	vector<int> a4{};
	print(s.removeElement(a4, 0), a4); // answer: 0
	return 0;
}
