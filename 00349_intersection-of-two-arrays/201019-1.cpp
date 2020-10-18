// https://leetcode-cn.com/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> m;
		for (auto e : nums1) {
			m.insert(e);
		}
		unordered_set<int> m2;
		for (auto e : nums2) {
			m2.insert(e);
		}
		vector<int> r;
		for (auto e : m2) {
			if (m.find(e) != m.end()) {
				r.push_back(e);
			}
		}
		return r;
	}
};

void print(const vector<int>& a)
{
	for (auto e : a) cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<int> nums1 = {1,2,2,1};
		vector<int> nums2 = {2,2};
		vector<int> r = s.intersection(nums1, nums2);
		print(r); // answer: [2]
	}
	{
		vector<int> nums1 = {4,9,5};
		vector<int> nums2 = {9,4,9,8,4};
		vector<int> r = s.intersection(nums1, nums2);
		print(r); // answer: [9,4]
	}
	return 0;
}
