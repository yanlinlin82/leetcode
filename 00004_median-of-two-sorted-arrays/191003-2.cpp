// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int p1 = 0, q1 = n1, k1 = n1 / 2;
		int p2 = 0, q2 = n2, k2 = (n1 + n2) / 2 - k1;
		for (;;) {
			if (k1 > 0 && k2 < n2 && nums1[k1 - 1] > nums2[k2]) {
				int s = (q2 - k2) / 2;
				if (s > k1 - p1) s = k1 - p1;
				if (s == 0) s = 1;
				q1 = k1 - 1; p2 = k2 + 1;
				k1 -= s; k2 += s;
				continue;
			} else if (k2 > 0 && k1 < n1 && nums2[k2 - 1] > nums1[k1]) {
				int s = (q1 - k1) / 2;
				if (s > k2 - p2) s = k2 - p2;
				if (s == 0) s = 1;
				p1 = k1 + 1; q2 = k2 - 1;
				k1 += s; k2 -= s;
				continue;
			}
			break;
		}
		double v;
		if (k1 < n1 && k2 < n2) {
			v = (nums1[k1] <= nums2[k2] ? nums1[k1] : nums2[k2]);
		} else if (k1 < n1) {
			v = nums1[k1];
		} else if (k2 < n2) {
			v = nums2[k2];
		} else {
			v = 0;
		}
		if ((n1 + n2) % 2 == 0) {
			double v2;
			if (k1 > 0 && k2 > 0) {
				v2 = (nums1[k1 - 1] >= nums2[k2 - 1] ? nums1[k1 - 1] : nums2[k2 - 1]);
			} else if (k1 > 0) {
				v2 = nums1[k1 - 1];
			} else if (k2 > 0) {
				v2 = nums2[k2 - 1];
			} else {
				v2 = 0;
			}
			v = (v + v2) / 2;
		}
		return v;
    }
};

int main()
{
    Solution s;

	{
		vector<int> nums1 = { 1, 3 };
		vector<int> nums2 = { 2 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 2.0
	}

	{
		vector<int> nums1 = { 1, 2 };
		vector<int> nums2 = { 3, 4 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 2.5
	}

	{
		vector<int> nums1 = { 1, 2, 3 };
		vector<int> nums2 = { 1, 2 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 2
	}

	{
		vector<int> nums1 = { 2, 3, 4 };
		vector<int> nums2 = { 1 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 2.5
	}

	{
		vector<int> nums1 = { 2, 3, 4 };
		vector<int> nums2 = { };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 3
	}

	{
		vector<int> nums1 = { 1, 3, 5 };
		vector<int> nums2 = { 2, 4, 6 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 3.5
	}

	{
		vector<int> nums1 = { 100000 };
		vector<int> nums2 = { 100001 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 100000.5
	}

	{
		vector<int> nums1 = { 1, 2, 4 };
		vector<int> nums2 = { 3, 5, 6, 7 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 4
	}

	{
		vector<int> nums1 = { 4, 5, 6, 7 };
		vector<int> nums2 = { 1 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 5
	}

	{
		vector<int> nums1 = { 1, 5, 6, 7 };
		vector<int> nums2 = { 1, 6 };
		printf("%f\n", s.findMedianSortedArrays(nums1, nums2)); // answer: 5.5
	}

    return 0;
}
