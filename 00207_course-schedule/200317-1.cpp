// https://leetcode-cn.com/problems/course-schedule/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, unordered_set<int>> o;
		for (auto& e : prerequisites) {
			int a = e[0], b = e[1];
			if (search(o, b, a)) return false;
			o[a].insert(b);
		}
		return true;
	}
private:
	bool search(const unordered_map<int, unordered_set<int>>& o, int from, int to) {
		if (from == to) return true;
		auto it = o.find(from);
		if (it == o.end()) return false;
		for (auto& e : it->second) {
			if (search(o, e, to)) return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<vector<int>> a = {{1,0}};
		cout << s.canFinish(2, a) << endl; // answer: true
	}
	{
		vector<vector<int>> a = {{1,0},{0,1}};
		cout << s.canFinish(2, a) << endl; // answer: false
	}
	return 0;
}
