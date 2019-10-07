// https://leetcode-cn.com/problems/container-with-most-water/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int n = height.size();
		int area = 0;
		for (int i = 0, j = n - 1; i < j;) {
			int a = height[i];
			int b = height[j];
			area = max(area, (j - i) * min(a, b));
			if (a <= b) {
				++i;
			} else {
				--j;
			}
		}
        return area;
    }
};

int main() {
    Solution s;
    vector<int> a1{1,8,6,2,5,4,8,3,7};
    printf("%d\n", s.maxArea(a1)); // answer: 49
    vector<int> a2{1,1};
    printf("%d\n", s.maxArea(a2)); // answer: 1
	vector<int> a3{2,3,4,5,18,17,6};
	printf("%d\n", s.maxArea(a3)); // answer: 17
    return 0;
}
