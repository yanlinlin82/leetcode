// https://leetcode-cn.com/problems/3sum/
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> r;
		unordered_map<int, int> cnt;
		set<int> cnt2;
		vector<int> u;
		for (auto e : nums) {
			int n = ++cnt[e];
			if (e != 0) {
				if (n == 1) {
					u.push_back(e);
				} else if (n == 2) {
					cnt2.insert(e);
				}
			}
		}
		auto it = cnt.find(0);
		if (it != cnt.end()) {
			if (it->second >= 3) {
				r.push_back(vector<int>{0, 0, 0});
			}
			for (auto it2 = cnt.begin(); it2 != cnt.end(); ++it2) {
				auto n = it2->first;
				if (n < 0 && cnt.find(-n) != cnt.end()) {
					r.push_back(vector<int>{n, 0, -n});
				}
			}
			cnt.erase(it);
		}
		for (auto e : cnt2) {
			int n = -(e + e);
			if (cnt.find(n) != cnt.end()) {
				r.push_back(vector<int>{e, e, n});
			}
		}
		sort(u.begin(), u.end());
		int n = u.size();
		for (int i = 0; i + 1 < n; ++i) {
			int a = u[i];
			for (int j = i + 1; j < n; ++j) {
				int b = u[j];
				int c = -(a + b);
				if (c > b && cnt.find(c) != cnt.end()) {
					r.push_back(vector<int>{a, b, c});
				}
			}
		}
		return r;
	}
};

void print(const vector<vector<int>>& r)
{
	printf("[");
	for (auto a : r) {
		printf(" [");
		for (auto e : a) {
			printf(" %d", e);
		}
		printf(" ]");
	}
	printf("]\n");
}

int main() {
	Solution s;
	vector<int> a1{-1, 0, 1, 2, -1, -4};
	print(s.threeSum(a1)); // answer: [ [-1,0,1], [-1,-1,2] ]
	vector<int> a2{3,0,-2,-1,1,2};
	print(s.threeSum(a2)); // answer: [ [-2,-1,3], [-1,0,1], [-2,0,2] ]
	return 0;
}
