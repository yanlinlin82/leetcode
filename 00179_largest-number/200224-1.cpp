// https://leetcode-cn.com/problems/largest-number/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> a(nums.size());
		for (int i = 0; i < nums.size(); ++i) a[i] = to_string(nums[i]);
		sort(a.begin(), a.end(), compare);
		if (a.empty() || a.front() == "0") return "0";
		string s;
		for (auto& e : a) s += e;
		return s;
	}
private:
	static bool compare(const string& a, const string& b) {
		const char* p = a.c_str();
		const char* q = b.c_str();
		for (; *p || *q; ++p, ++q) {
			if (!*p) p = a.c_str();
			if (!*q) q = b.c_str();
			if (*p < *q) return false;
			if (*p > *q) return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	{
		vector<int> a = {10,2};
		cout << s.largestNumber(a) << endl; // answer: "210"
	}
	{
		vector<int> a = {3,30,34,5,9};
		cout << s.largestNumber(a) << endl; // answer: "9534330"
	}
	{
		vector<int> a = {1231,123};
		cout << s.largestNumber(a) << endl; // answer: "1231231"
	}
	{
		vector<int> a = {0,0};
		cout << s.largestNumber(a) << endl; // answer: "0"
	}
	{
		vector<int> a = {3,43,48,94,85,33,64,32,63,66};
		cout << s.largestNumber(a) << endl; // answer: "9485666463484333332"
	}
	return 0;
}
