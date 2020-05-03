// https://leetcode-cn.com/problems/summary-ranges/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int a = numeric_limits<int>::max();
		int b = numeric_limits<int>::min();
		for (auto e : nums) {
			if (a > b) {
				a = b = e;
			} else if (b + 1 == e) {
				b = e;
			} else {
				if (a == b) {
					res.push_back(to_string(a));
				} else {
					res.push_back(to_string(a) + "->" + to_string(b));
				}
				a = b = e;
			}
		}
		if (a < b) {
			res.push_back(to_string(a) + "->" + to_string(b));
		} else if (a == b) {
			res.push_back(to_string(a));
		}
		return res;
	}
};

void print(vector<string>&& a) {
	cout << "[ ";
	for (auto e : a) cout << "\"" << e << "\" ";
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {0,1,2,4,5,7};
		print(s.summaryRanges(a)); // answer: ["0->2","4->5","7"]
	}
	{
		vector<int> a = {0,2,3,4,6,8,9};
		print(s.summaryRanges(a)); // answer: ["0","2->4","6","8->9"]
	}
	return 0;
}
