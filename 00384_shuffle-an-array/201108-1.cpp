// https://leetcode-cn.com/problems/shuffle-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	Solution(vector<int>& nums) {
		a = s = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return a;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		random_shuffle(s.begin(), s.end());
		return s;
	}

private:
	vector<int> a;
	vector<int> s;
};

void print(const vector<int>& a)
{
	for (auto e : a) cout << e << " ";
	cout << endl;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main()
{
	vector<int> a{1,2,3};
	Solution s(a);
	print(s.shuffle());
	print(s.reset());
	print(s.shuffle());
	return 0;
}
