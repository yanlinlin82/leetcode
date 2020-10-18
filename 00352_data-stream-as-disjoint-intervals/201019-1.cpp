// https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/
#include <iostream>
#include <vector>
using namespace std;

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
	}

	void addNum(int val) {
		for (int i = 0; i < a.size(); ++i) {
			if (val < a[i][0] - 1) {
				a.insert(a.begin() + i, vector<int>{val, val});
				return;
			} else if (val == a[i][0] - 1) {
				a[i][0] = val;
				return;
			} else if (val >= a[i][0] && val <= a[i][1]) {
				return;
			} else if (val == a[i][1] + 1) {
				if (i + 1 >= a.size() || val < a[i + 1][0] - 1) {
					a[i][1] = val;
				} else {
					a[i][1] = a[i + 1][1];
					a.erase(a.begin() + i + 1);
				}
				return;
			}
		}
		a.push_back(vector<int>{val, val});
	}

	vector<vector<int>> getIntervals() {
		return a;
	}
private:
	vector<vector<int>> a;
};

void print(const vector<vector<int>>& a) {
	for (auto& p : a) {
		cout << "[" << p[0] << "," << p[1] << "] ";
	}
	cout << endl;
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
int main()
{
	/*
	 * 例如，假设数据流中的整数为 1，3，7，2，6，…，每次的总结为：
	 * [1, 1]
	 * [1, 1], [3, 3]
	 * [1, 1], [3, 3], [7, 7]
	 * [1, 3], [7, 7]
	 * [1, 3], [6, 7]
	*/
	SummaryRanges s;
	s.addNum(1); print(s.getIntervals());
	s.addNum(3); print(s.getIntervals());
	s.addNum(7); print(s.getIntervals());
	s.addNum(2); print(s.getIntervals());
	s.addNum(6); print(s.getIntervals());
	return 0;
}
