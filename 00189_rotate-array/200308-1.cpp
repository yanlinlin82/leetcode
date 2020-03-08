// https://leetcode-cn.com/problems/rotate-array/
// 挑战失败：超出时间限制
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = (k % n) + (k < 0 ? n : 0);
		if (n <= 1 || k <= 0 || n == k) return;
		int count = 0;
		for (int i = 0; count < n; ++i) {
			for (int x = nums[i], curr = i;;) {
				int next = (curr + n - k) % n;
				++count;
				if (next == i) {
					nums[curr] = x;
					break;
				}
				nums[curr] = nums[next];
				curr = next;
				if (curr == i) break;
			}
		}
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
