// https://leetcode-cn.com/problems/combination-sum-iii/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		unordered_set<int> o;
		calc(k, n, res, o, 1);
		return res;
	}
private:
	void calc(int k, int n, vector<vector<int>>& res, unordered_set<int>& o, int start) {
		if (k == 0 && n == 0) {
			res.push_back(vector<int>(o.begin(), o.end()));
			return;
		}
		if (k > 0) {
			for (int i = start; i <= 9 && i <= n; ++i) {
				if (o.find(i) != o.end()) continue;
				o.insert(i);
				calc(k - 1, n - i, res, o, i + 1);
				o.erase(i);
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	cout << "[ ";
	for (auto& r : a) {
		cout << "[ ";
		for (auto e : r) {
			cout << e << " ";
		}
		cout << "] ";
	}
	cout << "]" << endl;
}

int main()
{
	Solution s;
	print(s.combinationSum3(3, 7)); // answer: [[1,2,4]]
	print(s.combinationSum3(3, 9)); // answer: [[1,2,6], [1,3,5], [2,3,4]]
	return 0;
}
