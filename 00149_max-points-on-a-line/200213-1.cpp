// https://leetcode-cn.com/problems/max-points-on-a-line/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		unordered_map<int, unordered_map<int, int>> counter; // x => (y => count)
		vector<pair<int, int>> unique; // [ (x, y) ]
		for (int i = 0; i < points.size(); ++i) {
			int x = points[i][0];
			int y = points[i][1];
			if (++counter[x][y] == 1) {
				unique.push_back(make_pair(x, y));
			}
		}
		int n = unique.size();
		if (n == 0) return 0;
		if (n <= 2) {
			int c = 0;
			for (auto it = counter.begin(); it != counter.end(); ++it) {
				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
					c += it2->second;
				}
			}
			return c;
		}
		int max = 0;
		for (int i = 0; i + 2 < n; ++i) {
			long int x1 = unique[i].first;
			long int y1 = unique[i].second;
			for (int j = i + 1; j + 1 < n; ++j) {
				long int x2 = unique[j].first;
				long int y2 = unique[j].second;
				long int dx = x2 - x1;
				long int dy = y2 - y1;
				int c = counter[x1][y1] + counter[x2][y2];
				for (int k = j + 1; k < n; ++k) {
					long int x3 = unique[k].first;
					long int y3 = unique[k].second;
					long int dx2 = x3 - x1;
					long int dy2 = y3 - y1;
					if (dx * dy2 == dx2 * dy) c += counter[x3][y3];
				}
				if (c > max) max = c;
			}
		}
		return max;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{1,1},{2,2},{3,3}};
		printf("%d\n", s.maxPoints(a)); // answer: 3
	}
	{
		vector<vector<int>> a = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
		printf("%d\n", s.maxPoints(a)); // answer: 4
	}
	{
		vector<vector<int>> a = {};
		printf("%d\n", s.maxPoints(a)); // answer: 0
	}
	{
		vector<vector<int>> a = {{1,1}};
		printf("%d\n", s.maxPoints(a)); // answer: 1
	}
	{
		vector<vector<int>> a = {{1,1},{1,3}};
		printf("%d\n", s.maxPoints(a)); // answer: 2
	}
	{
		vector<vector<int>> a = {{1,1},{1,1},{1,3}};
		printf("%d\n", s.maxPoints(a)); // answer: 3
	}
	{
		vector<vector<int>> a = {{0,9},{138,429},{115,359},{115,359},{-30,-102},{230,709},{-150,-686},{-135,-613},{-60,-248},{-161,-481},{207,639},{23,79},{-230,-691},{-115,-341},{92,289},{60,336},{-105,-467},{135,701},{-90,-394},{-184,-551},{150,774}};
		printf("%d\n", s.maxPoints(a)); // answer: 12
	}
	{
		vector<vector<int>> a = {{0,0},{0,0}};
		printf("%d\n", s.maxPoints(a)); // answer: 2
	}
	return 0;
}
