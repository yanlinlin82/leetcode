// https://leetcode-cn.com/problems/water-and-jug-problem/
#include <iostream>
using namespace std;

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (x + y < z) return false;
		if (x == 0 || y == 0) {
			return (z == 0 || x + y == z);
		}
		return z % calcGCD(x, y) == 0;
	}
private:
	int calcGCD(int x, int y) {
		while (x != y) {
			if (x > y) {
				x %= y;
				if (x == 0) x = y;
			} else {
				y %= x;
				if (y == 0) y = x;
			}
		}
		return x;
	}
};

int main()
{
	Solution s;
	cout << s.canMeasureWater(3, 5, 4) << endl; // answer: true
	cout << s.canMeasureWater(2, 6, 5) << endl; // answer: false
	return 0;
}
