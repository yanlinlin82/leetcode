// https://leetcode-cn.com/problems/find-peak-element/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		return findPeakElement(&nums[0], 0, n - 1);
	}
private:
	int findPeakElement(const int* a, int start, int end) {
		if (start >= end) return start;
		if (a[start] > a[start + 1]) return start;
		if (a[end - 1] < a[end]) return end;
		int mid = (start + end) / 2;
		if (a[mid - 1] < a[mid] && a[mid] > a[mid + 1]) return mid;
		if (a[mid - 1] > a[mid]) {
			return findPeakElement(a, start, mid - 1);
		} else {
			return findPeakElement(a, mid + 1, end);
		}
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		printf("%d\n", s.findPeakElement(a)); // answer: 2
	}
	{
		vector<int> a = {1,2,1,3,5,6,4};
		printf("%d\n", s.findPeakElement(a)); // answer: 1 or 5
	}
	return 0;
}
