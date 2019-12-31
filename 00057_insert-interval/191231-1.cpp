// https://leetcode-cn.com/problems/insert-interval/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		insert(intervals, newInterval[0], newInterval[1]);
		return intervals;
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
		vector<vector<int>> a = {{1,3},{6,9}};
		vector<int> b = {2,5};
		print(s.insert(a, b)); // answer: [[1,5],[6,9]]
	}
	{
		vector<vector<int>> a = {{1,2},{3,5},{6,7},{8,10},{12,16}};
		vector<int> b = {4,8};
		print(s.insert(a, b)); // answer: [[1,2],[3,10],[12,16]]
	}
	return 0;
}
