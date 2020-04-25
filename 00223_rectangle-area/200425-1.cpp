// https://leetcode-cn.com/problems/rectangle-area/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (A > C) swap(A, C);
		if (B > D) swap(B, D);
		if (E > G) swap(E, G);
		if (F > H) swap(F, H);
		long long area1 = (C - A) * (D - B);
		long long area2 = (G - E) * (H - F);
		long long overlapX = calcOverlap(A, C, E, G);
		long long overlapY = calcOverlap(B, D, F, H);
		return area1 + area2 - overlapX * overlapY;
	}
private:
	int calcOverlap(int s1, int e1, int s2, int e2) {
		if (e1 <= s2) return 0;
		if (s1 >= e2) return 0;
		return min(e1, e2) - max(s1, s2);
	}
};

int main()
{
	Solution s;
	cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl; // answer: 45
	return 0;
}
