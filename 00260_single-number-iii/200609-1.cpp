// https://leetcode-cn.com/problems/single-number-iii/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int, int> a;
		unordered_set<int> b;
		for (int x : nums) {
			int c = ++a[x];
			if (c == 1) {
				b.insert(x);
			} else {
				b.erase(x);
			}
		}
		vector<int> res;
		for (int x : b) {
			res.push_back(x);
		}
		return res;
	}
};

void print(const vector<int>& a)
{
	cout << "[ ";
	for (const auto& e : a) {
		cout << e << " ";
	}
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,1,3,2,5};
		print(s.singleNumber(a));
	}
	return 0;
}
