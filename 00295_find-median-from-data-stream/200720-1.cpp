// https://leetcode-cn.com/problems/find-median-from-data-stream/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
		a.push_back(num);
		sort(a.begin(), a.end());
    }

    double findMedian() {
		int n = a.size();
		if (n % 2 == 0) {
			return (a[n / 2 - 1] + a[n / 2]) / 2.0;
		} else {
			return a[n / 2];
		}
    }
private:
	vector<int> a;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
	{
		MedianFinder m;
		m.addNum(1);
		m.addNum(2);
		cout << m.findMedian() << endl; // answer: 1.5
		m.addNum(3);
		cout << m.findMedian() << endl; // answer: 2
	}
	return 0;
}
