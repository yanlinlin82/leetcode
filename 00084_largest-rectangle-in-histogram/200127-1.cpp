// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		//printf("============\n"); for (auto e : heights) { printf(" %d", e); }; printf("\n");
		int n = heights.size();
		if (n <= 0) return 0;
		if (n == 1) return heights[0];
		int max_height = 0;
		int max_area = 0;
		vector<node> m;
		for (int i = 0; i < n; ++i) {
			if (heights[i] < max_height) continue;
			if (heights[i] > max_height) {
				max_height = heights[i];
				m.clear();
				m.push_back(node(i,i,max_height));
			} else if (m.empty() || i > m.back().b + 1) {
				m.push_back(node(i,i,max_height));
			} else {
				++m.back().b;
			}
			int area = m.back().area();
			if (area > max_area) max_area = area;
		}
		//printf("max_height = %d, max_area = %d, ", max_height, max_area); for (auto e : m) { printf("[%d,%d,%d]{", e.a, e.b, e.h); for (int i = e.a; i <= e.b; ++i) { printf("%s%d",(i==e.a?"":","),heights[i]); }; printf("} "); }; printf("\n");
		if (max_height == 0) return 0;
		for (;;) {
			max_height = 0;
			for (int i = 0; i < m.size(); ++i) {
				int a = m[i].a;
				int b = m[i].b;
				if (a > 0 && b < n - 1) {
					if (heights[a - 1] >= heights[b + 1]) {
						--m[i].a; if (heights[m[i].a] < m[i].h) m[i].h = heights[m[i].a];
					} else {
						++m[i].b; if (heights[m[i].b] < m[i].h) m[i].h = heights[m[i].b];
					}
				} else if (a > 0) {
					--m[i].a; if (heights[m[i].a] < m[i].h) m[i].h = heights[m[i].a];
				} else if (b < n - 1) {
					++m[i].b; if (heights[m[i].b] < m[i].h) m[i].h = heights[m[i].b];
				} else {
					continue;
				}
				if (m[i].h > max_height) max_height = m[i].h;
				int area = m[i].area();
				if (area > max_area) max_area = area;
			}
			//printf("max_height = %d, max_area = %d, ", max_height, max_area); for (auto e : m) { printf("[%d,%d,%d]{", e.a, e.b, e.h); for (int i = e.a; i <= e.b; ++i) { printf("%s%d",(i==e.a?"":","),heights[i]); }; printf("} "); }; printf("\n");
			for (int i = 0; i <= m.size(); ++i) {
				int start = (i == 0 ? 0 : m[i - 1].b + 1);
				int end = (i < m.size() ? m[i].a : heights.size());
				for (int j = start; j < end; ++j) {
					if (heights[j] >= max_height) {
						if (i == 0 || j > m[i - 1].b + 1) {
							if (i < m.size()) {
								m.insert(m.begin() + i, node(j,j,heights[j]));
							} else {
								m.push_back(node(j,j,heights[j]));
							}
							int area = m[i].area();
							if (area > max_area) max_area = area;
							++i;
						} else {
							m[i - 1].b = j;
							int area = m[i - 1].area();
							if (area > max_area) max_area = area;
						}
						max_height = heights[j];
					}
				}
			}
			//printf("max_height = %d, max_area = %d, ", max_height, max_area); for (auto e : m) { printf("[%d,%d,%d]{", e.a, e.b, e.h); for (int i = e.a; i <= e.b; ++i) { printf("%s%d",(i==e.a?"":","),heights[i]); }; printf("} "); }; printf("\n");
			if ((long int)(max_height) * n < (long int)max_area) break; // 'long int' for very large test data set
		}
		return max_area;
	}
private:
	struct node {
		int a, b, h;
		explicit node(int aa = 0, int bb = 0, int hh = 0): a(aa), b(bb), h(hh) { }
		int area() const { return h * (b - a + 1); }
	};
};

int main()
{
	Solution s;
	{
		vector<int> a = {2,1,5,6,2,3};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 10
	}
	{
		vector<int> a = {};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 0
	}
	{
		vector<int> a = {5};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 5
	}
	{
		vector<int> a = {4,1,4};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 4
	}
	{
		vector<int> a = {4,2,4};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 6
	}
	{
		vector<int> a = {4,1,1,1,4};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 5
	}
	{
		vector<int> a = {0,0};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 0
	}
	{
		vector<int> a = {1,1,1};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 3
	}
	{
		vector<int> a = {5,5,1,7,1,1,5,2,7,6};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 12
	}
	{
		vector<int> a = {3,1,3,3,1,3,3,3,1,5,1};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 11
	}
	{
		vector<int> a = {3,0,3,3,0,3,3,3,0,5,0};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 9
	}
	{
		vector<int> a = {5,7,8,1,1,4,4,6,5,0,2};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 16
	}
	{
		vector<int> a = {4,2,3};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 6
	}
	{
		vector<int> a = {2,0,1,0,1,0};
		printf("%d\n", s.largestRectangleArea(a)); // answer: 2
	}
	return 0;
}
