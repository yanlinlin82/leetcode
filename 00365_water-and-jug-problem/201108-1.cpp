// https://leetcode-cn.com/problems/water-and-jug-problem/
// 挑战失败：超出时间限制
#include <iostream>
#include <utility>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		unordered_map<int, unordered_set<int>> visited;
		list<pair<int, int>> queue;
		queue.push_back(make_pair(0, 0));
		while (!queue.empty()) {
			int a = queue.front().first;
			int b = queue.front().second;
			queue.pop_front();
			if (a == z || b == z || a + b == z) return true;
			auto it = visited.find(a);
			if (it != visited.end()) {
				if (it->second.find(b) != it->second.end()) {
					continue;
				}
			}
			visited[a].insert(b);
			if (a != x) {
				queue.push_back(make_pair(x, b));
			}
			if (a != 0) {
				queue.push_back(make_pair(0, b));
			}
			if (b != y) {
				queue.push_back(make_pair(a, y));
			}
			if (b != 0) {
				queue.push_back(make_pair(a, 0));
			}
			if (a < x && b > 0) {
				int c = x - a;
				if (c > b) c = b;
				queue.push_back(make_pair(a + c, b - c));
			}
			if (a > 0 && b < y) {
				int c = y - b;
				if (c > a) c = a;
				queue.push_back(make_pair(a - c, b + c));
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.canMeasureWater(3, 5, 4) << endl; // answer: true
	cout << s.canMeasureWater(2, 6, 5) << endl; // answer: false
	return 0;
}
