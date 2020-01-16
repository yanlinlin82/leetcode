// https://leetcode-cn.com/problems/simplify-path/
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		const char* s = path.c_str();
		int n = path.size();
		vector<string> a;
		string dir;
		for (int i = 0; i <= n; ++i) {
			char c = path[i];
			if (c && c != '/') {
				dir += c;
			} else {
				if (dir == "..") {
					if (!a.empty()) {
						a.pop_back();
					}
				} else if (dir != "." && !dir.empty()) {
					a.push_back(dir);
				}
				dir.clear();
			}
		}
		string res = "/";
		for (int i = 0; i < a.size(); ++i) {
			if (i > 0) res += '/';
			res += a[i];
		}
		return res;
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.simplifyPath("/home/").c_str());                // answer: '/home'
	printf("%s\n", s.simplifyPath("/../").c_str());                  // answer: '/'
	printf("%s\n", s.simplifyPath("/home//foo/").c_str());           // answer: '/home/foo'
	printf("%s\n", s.simplifyPath("/a/./b/../../c/").c_str());       // answer: '/c'
	printf("%s\n", s.simplifyPath("/a/./b/../../c/").c_str());       // answer: '/c'
	printf("%s\n", s.simplifyPath("/a//b////c/d//././/..").c_str()); // answer: '/a/b/c'
	return 0;
}
