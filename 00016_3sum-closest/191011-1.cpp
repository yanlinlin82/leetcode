// https://leetcode-cn.com/problems/3sum-closest/
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        bool first = true;
        int last_sum = 0;
        int last_diff = 0;
        int n = nums.size();
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = i + 1; j + 1 < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (first || abs(sum - target) < last_diff) {
                        first = false;
                        last_sum = sum;
                        last_diff = abs(sum - target);
                    }
                }
            }
        }
        return last_sum;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    printf("%d\n", s.threeSumClosest(nums, target)); // answer: 2, (-1 + 2 + 1 = 2)
    return 0;
}
