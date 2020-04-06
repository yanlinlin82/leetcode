// https://leetcode-cn.com/problems/contains-duplicate/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> a;
		for (auto e : nums) {
			if (a.find(e) != a.end()) return true;
			a.insert(e);
		}
		return false;
    }
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3,1};
		cout << s.containsDuplicate(a) << endl; // answer: true
	}
	{
		vector<int> a = {1,2,3,4};
		cout << s.containsDuplicate(a) << endl; // answer: true
	}
	{
		vector<int> a = {1,1,1,3,3,4,3,2,4,2};
		cout << s.containsDuplicate(a) << endl; // answer: true
	}
	return 0;
}
