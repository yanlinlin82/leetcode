// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		auto a = split(preorder, ',');
		//for (auto e : a) cout << e << " "; cout << endl;
		int c = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] == "#") {
				++c;
			} else if (c >= 2) {
				--c;
			} else {
				return false;
			}
		}
		return c == 1;
	}
private:
	vector<string> split(string s, char sep) {
		vector<string> a;
		string::size_type pos = 0;
		for (;;) {
			string::size_type next = s.find(sep, pos);
			if (next == string::npos) {
				a.push_back(s.substr(pos));
				break;
			} else {
				a.push_back(s.substr(pos, next - pos));
				pos = next + 1;
			}
		}
		return a;
	}
};

int main()
{
	Solution s;
	cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl; // answer: true
	cout << s.isValidSerialization("1,#") << endl; // answer: false
	cout << s.isValidSerialization("9,#,#,1") << endl; // answer: false
	return 0;
}
