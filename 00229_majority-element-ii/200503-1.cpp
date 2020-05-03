// https://leetcode-cn.com/problems/majority-element-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> a;
		for (auto e : nums) ++a[e];
		int n = nums.size();
		vector<int> r;
		for (auto it = a.begin(); it != a.end(); ++it) {
			if (it->second > n / 3) {
				r.push_back(it->first);
			}
		}
		return r;
	}
};

void print(vector<int>&& a) {
	for (auto e : a) cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {3,2,3};
		print(s.majorityElement(a)); // answer: [3]
	}
	{
		vector<int> a = {1,1,1,3,3,2,2,2};
		print(s.majorityElement(a)); // answer: [1,2]
	}
	return 0;
}
