// https://leetcode-cn.com/problems/next-permutation/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		process(&nums[0], nums.size());
	}
private:
	void process(int* a, int n) {
		if (n < 2) return;
		if (n == 2) {
			swap(a[0], a[1]);
		} else if (!isLargest(a + 1, n - 1)) {
			process(a + 1, n - 1);
		} else if (a[0] >= a[1]) {
			for (int i = 0, j = n - 1; i < j; ++i, --j) {
				swap(a[i], a[j]);
			}
		} else {
			for (int i = n - 1; i > 0; --i) {
				if (a[0] < a[i]) {
					swap(a[0], a[i]);
					break;
				}
			}
			sort(a + 1, a + n);
		}
	}
	bool isLargest(const int* a, int n) {
		if (n < 2) {
			return true;
		} else if (n == 2) {
			return (a[0] >= a[1]);
		} else {
			return (a[0] >= a[1]) && isLargest(a + 1, n - 1);
		}
	}
};

void print(const vector<int>& a)
{
	for (const auto& e : a) {
		printf("%d ", e);
	}
	printf("\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = { 1, 2, 3 };
		s.nextPermutation(a);
		print(a); // answer: 1, 3, 2
	}
	{
		vector<int> a = { 3, 2, 1 };
		s.nextPermutation(a);
		print(a); // answer: 1, 2, 3
	}
	{
		vector<int> a = { 1, 1, 5 };
		s.nextPermutation(a);
		print(a); // answer: 1, 5, 1
	}
	{
		vector<int> a = { 1, 2, 3, 4 };
		s.nextPermutation(a);
		print(a); // answer: 1, 2, 4, 3
	}
	{
		vector<int> a = { 1, 1, 1, 1 };
		s.nextPermutation(a);
		print(a); // answer: 1, 1, 1, 1
	}
	{
		vector<int> a = { 1, 1, 5, 4 };
		s.nextPermutation(a);
		print(a); // answer: 1, 4, 1, 5
	}
	{
		vector<int> a = { 3, 2, 1, 1 };
		s.nextPermutation(a);
		print(a); // answer: 1, 1, 2, 3
	}
	{
		vector<int> a = { 3, 4, 1, 1 };
		s.nextPermutation(a);
		print(a); // answer: 4, 1, 1, 3
	}
	return 0;
}
