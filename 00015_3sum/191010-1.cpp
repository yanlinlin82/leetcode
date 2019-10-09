// https://leetcode-cn.com/problems/3sum/
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<int> copy;
        for (auto e : nums) {
            if (++cnt[e] <= 3) {
                copy.push_back(e);
            }
        }
        vector<vector<int>> r;
        unordered_map<int, set<int>> s;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < copy.size(); ++i) {
            m[copy[i]].push_back(i);
        }
        for (int i = 0; i + 1 < copy.size(); ++i) {
            for (int j = i + 1; j < copy.size(); ++j) {
                int v = -(copy[i] + copy[j]);
                auto it = m.find(v);
                if (it != m.end()) {
                    for (auto k : it->second) {
                        if (k > j) {
                            int a = copy[i];
                            int b = copy[j];
                            int c = copy[k];
                            if (a > b) swap(a, b);
                            if (a > c) swap(a, c);
                            if (b > c) swap(b, c);
                            auto it2 = s.find(a);
                            if (it2 != s.end()) {
                                auto it3 = it2->second.find(b);
                                if (it3 != it2->second.end()) {
                                    continue;
                                }
                            }
                            s[a].insert(b);
                            r.push_back(vector<int>{a, b, c});
                        }
                    }
                }
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> a{-1, 0, 1, 2, -1, -4};
    auto r = s.threeSum(a); // answer: [ [-1,0,1], [-1,-1,2] ]
    for (auto a : r) {
        printf("[");
        for (auto e : a) {
            printf(" %d", e);
        }
        printf(" ]\n");
    }
    return 0;
}
