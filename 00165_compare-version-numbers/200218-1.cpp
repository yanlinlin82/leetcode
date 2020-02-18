// https://leetcode-cn.com/problems/compare-version-numbers/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		return doComp(version1.c_str(), version2.c_str());
	}
private:
	int doComp(const char* p, const char* q) {
		while (*p || *q) {
			int a = 0; while (*p >= '0' && *p <= '9') { a = a * 10 + (*p - '0'); ++p; }
			int b = 0; while (*q >= '0' && *q <= '9') { b = b * 10 + (*q - '0'); ++q; }
			if (a < b) return -1;
			if (a > b) return 1;
			if (*p) ++p;
			if (*q) ++q;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.compareVersion("0.1", "1.1")); // answer: -1
	printf("%d\n", s.compareVersion("1.0.1", "1")); // answer: 1
	printf("%d\n", s.compareVersion("7.5.2.4", "7.5.3")); // answer: -1
	printf("%d\n", s.compareVersion("1.01", "1.001")); // answer: 0
	printf("%d\n", s.compareVersion("1.0", "1.0.0")); // answer: 0
	return 0;
}
