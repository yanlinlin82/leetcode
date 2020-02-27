// https://leetcode-cn.com/problems/repeated-dna-sequences/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> a;
		for (int i = 0; i + 10 <= s.size(); ++i) {
			++a[s.substr(i, 10)];
		}
		vector<string> r;
		for (auto it = a.begin(); it != a.end(); ++it) {
			if (it->second > 1) {
				r.push_back(it->first);
			}
		}
		return r;
	}
};

void print(vector<string>&& a)
{
	cout << "[ ";
	for (auto& s : a) cout << "'" << s << "' ";
	cout << "]" << endl;
}

int main()
{
	Solution s;
	print(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")); // answer: ["AAAAACCCCC", "CCCCCAAAAA"]
	return 0;
}
