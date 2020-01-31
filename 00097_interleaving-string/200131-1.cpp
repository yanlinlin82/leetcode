// https://leetcode-cn.com/problems/interleaving-string/
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		if (n1 + n2 != n3) return false;
		long int c[256] = { 0 };
		for (size_t i = 0; i < n1; ++i) ++c[(long int)(unsigned char)s1[i]];
		for (size_t i = 0; i < n2; ++i) ++c[(long int)(unsigned char)s2[i]];
		for (size_t i = 0; i < n3; ++i) if (--c[(long int)(unsigned char)s3[i]] < 0) return false;
		const char* p1 = s1.c_str(), *p2 = s2.c_str(), *p3 = s3.c_str();
		return check(p1, p2, p3);
	}
private:
	bool check(const char* p1, const char* p2, const char* p3) {
		if (!*p3) {
			return true;
		} else if (*p3 == *p1 && *p3 == *p2) {
			return check(p1+1, p2, p3+1) || check(p1, p2+1, p3+1);
		} else if (*p3 == *p1) {
			return check(p1+1, p2, p3+1);
		} else if (*p3 == *p2) {
			return check(p1, p2+1, p3+1);
		} else {
			return false;
		}
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbcbcac")); // answer: true
	printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbbaccc")); // answer: false
	return 0;
}
