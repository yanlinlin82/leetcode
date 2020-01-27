// https://leetcode-cn.com/problems/gray-code/
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> a{0};
		if (n > 0) {
			int count = 2; for (int i = 1; i < n; ++i) count *= 2;
			unordered_set<int> used; used.insert(0);
			a.resize(count);
			vector<int> b(count);
			int i = 1; b[1] = -1;
			for (;;) {
				//printf("i=%d, a=[", i); for (int j = 0; j < i; ++j) { printf("%s%d", (j>0?",":""), a[j]); }; printf("], b=["); for (int j = 0; j < i; ++j) { printf("%s%d", (j>0?",":""), b[j]); }; printf("], used=["); for (auto e : used) { printf("%d ", e); }; printf("]\n");
				if (++b[i] >= n) {
					if (--i <= 0) break;
					used.erase(a[i]);
				} else {
					a[i] = a[i - 1] ^ (1 << b[i]);
					if (used.find(a[i]) == used.end()) {
						used.insert(a[i]);
						if (++i >= count) break;
						b[i] = -1;
					}
				}
			}
		}
		return a;
	}
};

void print(const vector<int>& a)
{
	for (auto e : a) { printf("%d ", e); }
	printf("\n");
}

int main()
{
	Solution s;
	print(s.grayCode(2)); // answer: [0,1,3,2] or [0,2,3,1]
	print(s.grayCode(0)); // answer: [0]
	print(s.grayCode(1)); // answer: [0,1]
	print(s.grayCode(3)); // answer: [0,1,3,2,6,7,5,4]
	return 0;
}
