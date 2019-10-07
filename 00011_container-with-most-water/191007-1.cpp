// https://leetcode-cn.com/problems/container-with-most-water/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        for (int i = 0; i + 1 < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int newArea = (j - i) * min(height[i], height[j]);
                if (newArea > area) area = newArea;
            }
        }
        return area;
    }
};

int main() {
    Solution s;
    vector<int> a1{1,8,6,2,5,4,8,3,7};
    printf("%d\n", s.maxArea(a1)); // answer: 49
    return 0;
}
