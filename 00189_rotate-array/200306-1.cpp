// https://leetcode-cn.com/problems/rotate-array/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k <= 0 || nums.empty()) return;
		if (k > 1) rotate(nums, k - 1);
		int x = nums.back();
		for (int i = nums.size() - 1; i > 0; --i) {
			nums[i] = nums[i - 1];
		}
		nums[0] = x;
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
		vector<int> a = {1,2,3,4,5,6,7};
		s.rotate(a, 3);
		print(a); // answer: [5,6,7,1,2,3,4]
	}
	{
		vector<int> a = {-1,-100,3,99};
		s.rotate(a, 2);
		print(a); // answer: [3,99,-1,-100]
	}
	return 0;
}
