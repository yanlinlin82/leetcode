// https://leetcode-cn.com/problems/group-anagrams/
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, int> index;
		for (int i = 0; i < strs.size(); ++i) {
			string key = strs[i];
			sort(key.begin(), key.end());
			auto it = index.find(key);
			if (it == index.end()) {
				index[key] = res.size();
				res.push_back(vector<string>{strs[i]});
			} else {
				res[it->second].push_back(strs[i]);
			}
		}
		return res;
	}
};

void print(const vector<vector<string>>& a)
{
	printf("[\n");
	for (const auto& b : a) {
		printf("  [ ");
		for (int i = 0; i < b.size(); ++i) {
			if (i > 0) printf(", ");
			printf("\"%s\"", b[i].c_str());
		}
		printf(" ]\n");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<string> a = { "eat", "tea", "tan", "ate", "nat", "bat" };
		auto r = s.groupAnagrams(a);
		print(r); // answer: [ ["ate","eat","tea"], ["nat","tan"], ["bat"] ]
	}
	return 0;
}
