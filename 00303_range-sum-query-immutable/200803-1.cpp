// https://leetcode-cn.com/problems/range-sum-query-immutable/
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
		a = nums;
    }

    int sumRange(int i, int j) {
		int s = 0;
		for (int k = i; k <= j; ++k) {
			s += a[k];
		}
		return s;
    }
private:
	vector<int> a;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
int main()
{
	{
		vector<int> a = {-2, 0, 3, -5, 2, -1};
		NumArray n(a);
		cout << n.sumRange(0, 2) << endl; // answer: 1
		cout << n.sumRange(2, 5) << endl; // answer: -1
		cout << n.sumRange(0, 5) << endl; // answer: -3
	}
	return 0;
}
