// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m;
		for (auto e : nums1) ++m[e];
		unordered_map<int, int> m2;
		for (auto e : nums2) ++m2[e];
		vector<int> r;
		for (auto it = m.begin(); it != m.end(); ++it) {
			auto v = it->first;
			auto it2 = m2.find(v);
			if (it2 != m2.end()) {
				int c = min(it->second, it2->second);
				for (int i = 0; i < c; ++i) {
					r.push_back(v);
				}
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
		print(r); // answer: [2,2]
	}
	{
		vector<int> nums1 = {4,9,5};
		vector<int> nums2 = {9,4,9,8,4};
		vector<int> r = s.intersection(nums1, nums2);
		print(r); // answer: [4,9]
	}
	return 0;
}
