// https://leetcode-cn.com/problems/find-the-duplicate-number/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		unordered_set<int> o;
		for (auto e : nums) {
			if (o.find(e) != o.end()) {
				return e;
			}
			o.insert(e);
		}
		return 0;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,3,4,2,2};
		cout << s.findDuplicate(a) << endl; // answer: 2
	}
	{
		vector<int> a = {3,1,3,4,2};
		cout << s.findDuplicate(a) << endl; // answer: 3
	}
	return 0;
}
