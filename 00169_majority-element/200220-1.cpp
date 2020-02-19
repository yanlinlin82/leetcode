// https://leetcode-cn.com/problems/majority-element/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> c;
		int n = nums.size();
		for (int x : nums) {
			if (++c[x] > n / 2) return x;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {3,2,3};
		printf("%d\n", s.majorityElement(a)); // answer: 3
	}
	{
		vector<int> a = {2,2,1,1,1,2,2};
		printf("%d\n", s.majorityElement(a)); // answer: 2
	}
	return 0;
}
