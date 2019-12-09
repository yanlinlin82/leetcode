// https://leetcode-cn.com/problems/combination-sum/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		vector<int> counts;
		process(results, candidates, counts, target);
		return results;
	}
private:
	void process(vector<vector<int>>& results, const vector<int>& candidates,
			vector<int>& counts, int target) {
		if (counts.size() < candidates.size()) {
			int i = counts.size();
			for (int c = target / candidates[i]; c >= 0; --c) {
				counts.push_back(c);
				process(results, candidates, counts, target - candidates[i] * c);
				counts.pop_back();
			}
		} else {
			if (target == 0) {
				vector<int> item;
				for (int i = 0; i < counts.size(); ++i) {
					for (int j = 0; j < counts[i]; ++j) {
						item.push_back(candidates[i]);
					}
				}
				results.push_back(item);
			}
		}
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (const auto& e : a) {
		printf("  [ ");
		for (auto e2 : e) {
			printf("%d ", e2);
		}
		printf("]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = { 2, 3, 6, 7 };
		print(s.combinationSum(a, 7)); // answer: [ [7], [2,2,3] ]
	}
	{
		vector<int> a = { 2, 3, 5 };
		print(s.combinationSum(a, 8)); // answer: [ [2,2,2,2], [2,3,3], [3,5] ]
	}
	return 0;
}
