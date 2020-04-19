// https://leetcode-cn.com/problems/contains-duplicate-iii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		vector<pair<int, int>> a; // { number, index }
		for (int i = 0; i < nums.size(); ++i) {
			a.push_back(make_pair(nums[i], i));
		}
		sort(a.begin(), a.end(), compare);
		for (int i = 0; i + 1 < a.size(); ++i) {
			int x = a[i].first;
			for (int j = i + 1; j < a.size(); ++j) {
				int y = a[j].first;
				if (y > x + t) break;
				if (abs(a[i].second - a[j].second) <= k) return true;
			}
		}
		return false;
	}
private:
	static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		cout << s.containsNearbyAlmostDuplicate(a, 3, 0) << endl; // answer: true
	}
	{
		vector<int> a = {1,0,1,1};
		cout << s.containsNearbyAlmostDuplicate(a, 1, 2) << endl; // answer: true
	}
	{
		vector<int> a = {1,5,9,1,5,9};
		cout << s.containsNearbyAlmostDuplicate(a, 2, 3) << endl; // answer: false
	}
	{
		vector<int> a = {0,2147483647};
		cout << s.containsNearbyAlmostDuplicate(a, 1, 2147483647) << endl; // answer: true
	}
	{
		vector<int> a = {-1,2147483647};
		cout << s.containsNearbyAlmostDuplicate(a, 1, 2147483647) << endl; // answer: false
	}
	return 0;
}
