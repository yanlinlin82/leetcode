// https://leetcode-cn.com/problems/merge-sorted-array/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		int* a = &nums1[0];
		int* b = &nums2[0];
		int* target = a + (m + n - 1);
		int* a_end = a - 1;
		int* b_end = b - 1;
		a += m - 1;
		b += n - 1;
		for (;;) {
			if (a != a_end && b != b_end) {
				if (*a >= *b) {
					*target-- = *a--;
				} else {
					*target-- = *b--;
				}
			} else if (a != a_end) {
				*target-- = *a--;
			} else if (b != b_end) {
				*target-- = *b--;
			} else {
				break;
			}
		}
	}
};

void print(const vector<int>& a)
{
	for (auto e : a) { printf("%d ", e); }
	printf("\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,0,0,0};
		vector<int> b = {2,5,6};
		s.merge(a, 3, b, 3);
		print(a);
	}
	return 0;
}
