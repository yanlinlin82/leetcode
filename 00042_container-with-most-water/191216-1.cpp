// https://leetcode-cn.com/problems/trapping-rain-water/
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		set<int> hval;
		for (auto e : height) {
			hval.insert(e);
		}
		int s = 0;
		int lastHval = 0;
		for (auto h : hval) {
			bool metLeft = false;
			int pool = 0;
			for (int i = 0; i < height.size(); ++i) {
				if (height[i] >= h) {
					if (!metLeft) {
						metLeft = true;
					} else {
						if (pool > 0) {
							s += pool;
							pool = 0;
						}
					}
				} else {
					if (metLeft) {
						pool += h - lastHval;
					}
				}
			}
			if (!metLeft) break;
			lastHval = h;
		}
		return s;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
		printf("%d\n", s.trap(a)); // answer: 6
	}
	return 0;
}
