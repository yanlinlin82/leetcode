// https://leetcode-cn.com/problems/russian-doll-envelopes/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		set<int> w, h;
		for (auto e : envelopes) {
			w.insert(e[0]);
			h.insert(e[1]);
		}
		map<int, int> ww, hh;
		int c = 0;
		for (auto e : w) {
			ww[e] = ++c;
		}
		c = 0;
		for (auto e : h) {
			hh[e] = ++c;
		}
		vector<vector<int>> m(h.size() + 1);
		for (auto& r : m) {
			r.resize(w.size() + 1);
		}
		for (auto e : envelopes) {
			m[hh[e[1]]][ww[e[0]]] = 1;
		}
		for (int i = 1; i < m.size(); ++i) {
			for (int j = 1; j < m[i].size(); ++j) {
				m[i][j] = max(m[i - 1][j - 1] + m[i][j], max(m[i - 1][j], m[i][j - 1]));
			}
		}
		return m.back().back();
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
		cout << s.maxEnvelopes(envelopes) << endl; // answer: 3，组合为: [2,3] => [5,4] => [6,7]
	}
	return 0;
}
