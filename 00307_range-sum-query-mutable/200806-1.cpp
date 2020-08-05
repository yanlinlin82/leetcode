// https://leetcode-cn.com/problems/range-sum-query-mutable/
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		a = nums;
	}

	void update(int i, int val) {
		a[i] = val;
	}

	int sumRange(int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; ++k) {
			sum += a[k];
		}
		return sum;
	}
private:
	vector<int> a;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
int main()
{
	{
		vector<int> a = {1, 3, 5};
		NumArray n(a);
		cout << n.sumRange(0, 2) << endl; //answer: 9
		n.update(1, 2);
		cout << n.sumRange(0, 2) << endl; //answer: 8
	}
	return 0;
}
