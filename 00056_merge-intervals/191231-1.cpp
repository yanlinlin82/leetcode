// https://leetcode-cn.com/problems/merge-intervals/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> a;
		for (const auto& r : intervals) {
			insert(a, r[0], r[1]);
		}
		return a;
	}
private:
	void insert(vector<vector<int>>& a, int start, int end) {
		for (int i = 0; i < a.size(); ++i) {
			if (end < a[i][0]) {
				a.insert(a.begin() + i, vector<int>{start, end});
				return;
			} else if (start <= a[i][1]) {
				if (a[i][0] > start) { a[i][0] = start; }
				if (a[i][1] < end) { a[i][1] = end; }
				while (i + 1 < a.size() && a[i][1] >= a[i + 1][0]) {
					if (a[i][1] < a[i + 1][1]) { a[i][1] = a[i + 1][1]; }
					a.erase(a.begin() + i + 1);
				}
				return;
			}
		}
		a.push_back(vector<int>{start, end});
	}
};

void print(const vector<vector<int>>& a)
{
	printf("[");
	for (int i = 0; i < a.size(); ++i) {
		if (i > 0) printf(",");
		printf("[%d,%d]", a[i][0], a[i][1]);
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
		print(s.merge(a)); // answer: [[1,6],[8,10],[15,18]]
	}
	{
		vector<vector<int>> a = {{1,4},{4,5}};
		print(s.merge(a)); // answer: [[1,5]]
	}
	{
		vector<vector<int>> a = {{1,4},{5,6}};
		print(s.merge(a)); // answer: [[1,6]]
	}
	{
		vector<vector<int>> a = {{1,4},{0,0}};
		print(s.merge(a)); // answer: [[0,0],[1,4]]
	}
	{
		vector<vector<int>> a = {{2,3},{4,5},{6,7},{8,9},{1,10}};
		print(s.merge(a)); // answer: [[1,10]]
	}
	return 0;
}
