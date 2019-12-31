// https://leetcode-cn.com/problems/insert-interval/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
		int start = newInterval[0];
		int end = newInterval[1];
		if (n == 0) {
			intervals.push_back(vector<int>{start, end});
		} else if (end < intervals[0][0]) {
			intervals.insert(intervals.begin(), vector<int>{start, end});
		} else if (start > intervals[n - 1][1]) {
			intervals.push_back(vector<int>{start, end});
		} else {
			int i = 0, j = n - 1;
			while (i < j) {
				int k = (i + j) / 2;
				if (intervals[k][1] < start) {
					i = k + 1;
				} else if (intervals[k][0] > end) {
					j = k - 1;
				} else {
					i = j = k;
					break;
				}
			}
			if (end < intervals[i][0]) {
				intervals.insert(intervals.begin() + i, vector<int>{start, end});
			} else if (start > intervals[i][1]) {
				intervals.insert(intervals.begin() + i + 1, vector<int>{start, end});
			} else {
				if (intervals[i][0] > start) { intervals[i][0] = start; }
				if (intervals[i][1] < end) { intervals[i][1] = end; }
				while (i + 1 < intervals.size() && intervals[i][1] >= intervals[i + 1][0]) {
					if (intervals[i][1] < intervals[i + 1][1]) {
						intervals[i][1] = intervals[i + 1][1];
					}
					intervals.erase(intervals.begin() + i + 1);
				}
				while (i > 0 && intervals[i - 1][1] >= intervals[i][0]) {
					if (intervals[i][0] > intervals[i - 1][0]) {
						intervals[i][0] = intervals[i - 1][0];
					}
					intervals.erase(intervals.begin() + i - 1);
					--i;
				}
			}
		}
		return intervals;
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
		vector<vector<int>> a = {{1,3},{6,9}};
		vector<int> b = {2,5};
		print(s.insert(a, b)); // answer: [[1,5],[6,9]]
	}
	{
		vector<vector<int>> a = {{1,2},{3,5},{6,7},{8,10},{12,16}};
		vector<int> b = {4,8};
		print(s.insert(a, b)); // answer: [[1,2],[3,10],[12,16]]
	}
	{
		vector<vector<int>> a = {{3,5},{12,15}};
		vector<int> b = {6,6};
		print(s.insert(a, b)); // answer: [[3,5][6,6],[12,15]]
	}
	return 0;
}
