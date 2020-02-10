// https://leetcode-cn.com/problems/single-number-ii/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		unordered_map<int, int> a;
		for (auto e : nums) {
			auto it = a.find(e);
			if (it == a.end()) {
				a.insert(make_pair(e, 1));
			} else if (it->second == 1) {
				++it->second;
			} else {
				a.erase(it);
			}
		}
		return a.begin()->first;
    }
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,2,3,2};
		printf("%d\n", s.singleNumber(a)); // answer: 3
	}
	{
		vector<int> a = {0,1,0,1,0,1,99};
		printf("%d\n", s.singleNumber(a)); // answer: 99
	}
	return 0;
}
