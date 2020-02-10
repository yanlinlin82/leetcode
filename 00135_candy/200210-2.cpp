// https://leetcode-cn.com/problems/candy/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		//printf("[ "); for (auto e : ratings) printf("%d ", e); printf("]\n");
		int n = ratings.size();
		int sum = 0;
		int curr = 1;
		//printf("=>");
		for (int i = 0; i < n;) {
			if (i + 1 < n && ratings[i] < ratings[i + 1]) {
				int k = 1;
				while (i + k < n && ratings[i + k - 1] < ratings[i + k]) ++k;
				//printf("up(i=%d,k=%d)", i, k);
				sum += (k - 1) * k / 2;
				curr = k;
				i += k - 1;
			} else if (i + 1 < n && ratings[i] > ratings[i + 1]) {
				int k = 1;
				while (i + k < n && ratings[i + k - 1] > ratings[i + k]) ++k;
				//printf("down(i=%d,k=%d)", i, k);
				if (curr <= k) {
					sum += k * (k + 1) / 2 - 1;
				} else {
					sum += curr + (k - 1) * k / 2 - 1;
				}
				curr = 1;
				i += k - 1;
			} else {
				//printf("(i=%d)", i);
				sum += curr;
				++i;
				curr = 1;
			}
			//printf("%d ", sum);
		}
		//printf("\n");
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
	{
		vector<int> a = {1,3,2,1};
		printf("%d\n", s.candy(a)); // answer: 7
	}
	return 0;
}
