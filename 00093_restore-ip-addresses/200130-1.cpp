// https://leetcode-cn.com/problems/restore-ip-addresses/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> r;
		const char* p = s.c_str();
		int n = s.size();
		for (size_t a = 1; a <= 3; ++a) {
			if (!valid(p, a)) continue;
			for (size_t b = 1; b <= 3; ++b) {
				if (!valid(p + a, b)) continue;
				for (size_t c = 1; c <= 3; ++c) {
					if (!valid(p + a + b, c)) continue;
					if (valid(p + a + b + c, n - a - b - c)) {
						r.push_back(s.substr(0, a) + "." + s.substr(a, b) + "." + s.substr(a + b, c) + "." + s.substr(a + b + c));
					}
				}
			}
		}
		return r;
	}
private:
	bool valid(const char* p, int size) {
		if (size <= 0 || size > 3) return false;
		if (size == 1) return true;
		if (size == 2) return (*p != '0');
		return (*p == '1' || (*p == '2' && *(p+1) < '5') || (*p == '2' && *(p+1) == '5' && *(p+2) <= '5'));
	}
};

void print(const vector<string>& a)
{
	printf("[ ");
	for (auto e : a) { printf("%s ", e.c_str()); }
	printf("]\n");
}

int main()
{
	Solution s;
	print(s.restoreIpAddresses("25525511135")); // ["255.255.11.135", "255.255.111.35"]
	print(s.restoreIpAddresses("010010")); // ["0.10.0.10","0.100.1.0"]
	return 0;
}
