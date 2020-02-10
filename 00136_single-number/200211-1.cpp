// https://leetcode-cn.com/problems/single-number/
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> a;
		for (auto e : nums) {
			if (a.find(e) == a.end()) {
				a.insert(e);
			} else {
				a.erase(e);
			}
		}
		return *a.begin();
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,2,1};
		printf("%d\n", s.singleNumber(a)); // answer: 1
	}
	{
		vector<int> a = {4,1,2,1,2};
		printf("%d\n", s.singleNumber(a)); // answer: 4
	}
	return 0;
}
