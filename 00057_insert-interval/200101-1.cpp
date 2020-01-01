// https://leetcode-cn.com/problems/insert-interval/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<vector<int>>& a)
{
	printf("[");
	for (int i = 0; i < a.size(); ++i) {
		if (i > 0) printf(",");
		printf("[%d,%d]", a[i][0], a[i][1]);
	}
	printf("]\n");
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
		if (n == 0) {
			return vector<vector<int>>{newInterval};
		}
		int start = newInterval[0];
		int end = newInterval[1];
		int a = findWithLeftSpace(intervals, start);
		int b = findWithRightSpace(intervals, end);
		//printf("=============\n"); print(intervals); printf("find(%d => %d, %d => %d)\n", start, a, end, b);
		if (b < 0) {
			intervals.insert(intervals.begin(), newInterval);
		} else if (a >= n) {
			intervals.push_back(newInterval);
		} else if (a > b) {
			intervals.insert(intervals.begin() + a, newInterval);
		} else {
			if (a < b) {
				intervals[a][1] = intervals[b][1];
				intervals.erase(intervals.begin() + a + 1, intervals.begin() + b + 1);
			}
			if (start < intervals[a][0]) {
				intervals[a][0] = start;
			}
			if (end > intervals[a][1]) {
				intervals[a][1] = end;
			}
		}
		return intervals;
    }
private:
	int findWithLeftSpace(const vector<vector<int>>& a, int x) {
		int n = a.size();
		if (n == 0 || x > a[n - 1][1]) return n;
		int i = 0, j = n - 1;
		while (i < j) {
			int k = (i + j) / 2;
			if (x > a[k][1]) {
				i = k + 1;
			} else {
				j = k;
			}
		}
		return i;
	}
	int findWithRightSpace(const vector<vector<int>>& a, int x) {
		int n = a.size();
		if (n == 0 || x < a[0][0]) return -1;
		int i = 0, j = n - 1;
		while (i < j) {
			int k = (i + j + 1) / 2;
			if (x < a[k][0]) {
				j = k - 1;
			} else {
				i = k;
			}
		}
		return i;
	}
};

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
		vector<vector<int>> a = {{1,3}};
		vector<int> b = {-1,0};
		print(s.insert(a, b)); // answer: [[-1,0],[1,3]]
	}
	{
		vector<vector<int>> a = {{1,3}};
		vector<int> b = {0,4};
		print(s.insert(a, b)); // answer: [[0,4]]
	}
	{
		vector<vector<int>> a = {{1,3}};
		vector<int> b = {4,5};
		print(s.insert(a, b)); // answer: [[1,3],[4,5]]
	}
	{
		vector<vector<int>> a = {{3,5},{12,15}};
		vector<int> b = {6,6};
		print(s.insert(a, b)); // answer: [[3,5],[6,6],[12,15]]
	}
	return 0;
}
