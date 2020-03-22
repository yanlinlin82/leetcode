// https://leetcode-cn.com/problems/course-schedule-ii/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, int> in, out;
		unordered_map<int, unordered_set<int>> m;
		for (int i = 0; i < numCourses; ++i) {
			in[i] = 0; out[i] = 0;
		}
		for (auto& e : prerequisites) {
			int after = e[0], before = e[1];
			++out[before]; ++in[after]; m[before].insert(after);
		}
		vector<int> res;
		while (!in.empty()) {
			int before = -1;
			for (auto it = in.begin(); it != in.end(); ++it) {
				if (it->second == 0) {
					before = it->first;
					in.erase(it);
					break;
				}
			}
			if (before < 0) return vector<int>();
			res.push_back(before);
			auto it = m.find(before);
			if (it != m.end()) {
				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
					int after = *it2;
					--out[before]; --in[after];
				}
			}
		}
		return res;
	}
};

void print(const vector<int>& a)
{
	cout << "[ "; for (auto& e : a) cout << e << " "; cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{1,0}};
		vector<int> b = s.findOrder(2, a);
		print(b); // answer: [0,1]
	}
	{
		vector<vector<int>> a = {{1,0},{2,0},{3,1},{3,2}};
		vector<int> b = s.findOrder(4, a);
		print(b); // answer: [0,1,2,3] or [0,2,1,3]
	}
	return 0;
}
