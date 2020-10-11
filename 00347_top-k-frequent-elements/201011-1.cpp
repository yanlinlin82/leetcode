// https://leetcode-cn.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto x : nums) ++m[x];
		vector<pair<int, int>> a;
		for (auto e : m) a.push_back(e);
		sort(a.begin(), a.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return (a.second > b.second); });
		vector<int> b;
		for (int i = 0; i < a.size() && i < k; ++i) {
			b.push_back(a[i].first);
		}
		return b;
	}
};

void print(const vector<int>& a)
{
	for (auto x : a) cout << x << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,1,1,2,2,3};
		print(a);
		vector<int> b = s.topKFrequent(a, 2);
		print(b); // answer: [1,2]
	}
	{
		vector<int> a = {1};
		print(a);
		vector<int> b = s.topKFrequent(a, 1);
		print(b); // answer: [1]
	}
	{
		vector<int> a = {1,2};
		print(a);
		vector<int> b = s.topKFrequent(a, 2);
		print(b); // answer: [1,2]
	}
	return 0;
}
