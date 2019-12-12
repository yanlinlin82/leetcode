// https://leetcode-cn.com/problems/combination-sum-ii/
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		candidate_counts.clear();
		candidate_numbers.clear();
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidate_counts.find(candidates[i]) == candidate_counts.end()) {
				candidate_numbers.push_back(candidates[i]);
			}
			++candidate_counts[candidates[i]];
		}
		sort(candidate_numbers.begin(), candidate_numbers.end(), greater<int>());
		vector<vector<int>> results;
		vector<int> counts;
		process(results, counts, target);
		return results;
	}
private:
	void process(vector<vector<int>>& results, vector<int>& counts, int target) {
		if (counts.size() < candidate_numbers.size()) {
			int i = counts.size();
			int c = target / candidate_numbers[i];
			if (c >= candidate_counts[candidate_numbers[i]]) {
				c = candidate_counts[candidate_numbers[i]];
			}
			for (; c >= 0; --c) {
				counts.push_back(c);
				process(results, counts, target - candidate_numbers[i] * c);
				counts.pop_back();
			}
		} else {
			if (target == 0) {
				vector<int> item;
				for (int i = 0; i < counts.size(); ++i) {
					for (int j = 0; j < counts[i]; ++j) {
						item.push_back(candidate_numbers[i]);
					}
				}
				results.push_back(item);
			}
		}
	}
	unordered_map<int, int> candidate_counts;
	vector<int> candidate_numbers;
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
		vector<int> a = {10,1,2,7,6,1,5};
		print(s.combinationSum2(a, 8)); // answer: [ [1,7], [1,2,5], [2,6], [1,1,6] ]
	}
	{
		vector<int> a = {2,5,2,1,2};
		print(s.combinationSum2(a, 5)); // answer: [ [1,2,2], [5] ]
	}
	{
		vector<int> a = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
		print(s.combinationSum2(a, 27)); // answer:
	}
	return 0;
}
