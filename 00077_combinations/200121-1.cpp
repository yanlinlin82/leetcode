// https://leetcode-cn.com/problems/combinations/
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> a;
		vector<int> value(k);
		doCombine(a, n, k, value, 0);
		return a;
	}
private:
	static void doCombine(vector<vector<int>>& results, int n, int k, vector<int>& value, int i) {
		if (i >= value.size()) {
			results.push_back(value);
		} else {
			for (value[i] = (i == 0 ? 1 : value[i - 1] + 1); value[i] <= n; ++value[i]) {
				doCombine(results, n, k, value, i + 1);
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (auto e : a) {
		printf("  [");
		for (auto e2 : e) {
			printf(" %d", e2);
		}
		printf(" ]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	print(s.combine(0, 0)); // answer: [ [] ]
	print(s.combine(1, 1)); // answer: [ [1] ]
	print(s.combine(2, 1)); // answer: [ [1], [2] ]
	print(s.combine(3, 2)); // answer: [ [1,2], [1,3], [2,3] ]
	print(s.combine(4, 2)); // answer: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4] ]
	return 0;
}
