// https://leetcode-cn.com/problems/plus-one/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty()) {
			digits.push_back(1);
		} else {
			int i = digits.size() - 1;
			while (i >= 0) {
				if (++digits[i] <= 9) return digits;
				digits[i] %= 10;
				--i;
			}
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

void print(const vector<int>& a)
{
	for (const auto& e : a) {
		printf("%d ", e);
	}
	printf("\n");
}

int main()
{
	Solution s;
	{
		vector<int> a = {1,2,3};
		print(s.plusOne(a)); // answer: [1,2,4]
	}
	{
		vector<int> a = {4,3,2,1};
		print(s.plusOne(a)); // answer: [4,3,2,2]
	}
	{
		vector<int> a = {9,9};
		print(s.plusOne(a)); // answer: [1,0,0]
	}
	return 0;
}
