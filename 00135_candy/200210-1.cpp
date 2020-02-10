// https://leetcode-cn.com/problems/candy/
// 挑战失败：超出时间限制
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> a(n);
		for (int i = 0; i < n; ++i) a[i] = 1;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && ratings[i - 1] > ratings[i]) {
				for (int k = i; k > 0; --k) {
					if (ratings[k - 1] <= ratings[k]) break;
					if (a[k - 1] < a[k] + 1) {
						a[k - 1] = a[k] + 1;
					}
				}
			}
			if (i + 1 < n && ratings[i] < ratings[i + 1]) {
				for (int k = i; k + 1 < n; ++k) {
					if (ratings[k] >= ratings[k + 1]) break;
					if (a[k + 1] < a[k] + 1) {
						a[k + 1] = a[k] + 1;
					}
				}
			}
		}
		//for (auto e : a) printf("%d ", e); printf("\n");
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
		}
		return sum;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {1,0,2};
		printf("%d\n", s.candy(a)); // answer: 5
	}
	{
		vector<int> a = {1,2,2};
		printf("%d\n", s.candy(a)); // answer: 4
	}
	{
		vector<int> a = {5};
		printf("%d\n", s.candy(a)); // answer: 1
	}
	{
		vector<int> a = {2,3,4,3,2};
		printf("%d\n", s.candy(a)); // answer: 9
	}
	return 0;
}
