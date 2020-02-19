// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0; i + 1 < numbers.size(); ++i) {
			for (int j = i + 1; j < numbers.size(); ++j) {
				int a = numbers[i] + numbers[j];
				if (a == target) return vector<int>{i + 1, j + 1};
				if (a > target) break;
			}
		}
		return vector<int>{0, 0};
	}
};

void print(vector<int>&& a)
{
	printf("[ ");
	for (auto& e : a) printf("%d ", e);
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {2, 7, 11, 15};
		print(s.twoSum(a, 9)); // answer: [1,2]
	}
	return 0;
}
