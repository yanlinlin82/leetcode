// https://leetcode-cn.com/problems/reconstruct-itinerary/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, map<string, int>> m;
		for (const auto& t : tickets) {
			++m[t[0]][t[1]];
		}
		vector<string> a = { "JFK" };
		fly(m, a, tickets.size());
		return a;
	}
private:
	bool fly(unordered_map<string, map<string, int>>& m, vector<string>& a, int n) {
		//cout << "fly (" << n << "): "; for (auto e : a) cout << e << " "; cout << endl;
		if (n == 0) return true;
		string curr = a.back();
		auto it = m.find(curr);
		if (it == m.end()) return false;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			if (it2->second > 0) {
				--it2->second;
				a.push_back(it2->first);
				if (fly(m, a, n - 1)) return true;
				a.pop_back();
				++it2->second;
			}
		}
		return false;
	}
};

void print(const vector<string>& a)
{
	for (auto e : a) cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	{
		vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
		auto a = s.findItinerary(tickets);
		print(a); // answer: ["JFK", "MUC", "LHR", "SFO", "SJC"]
	}
	{
		vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
		auto a = s.findItinerary(tickets);
		print(a); // answer: ["JFK","ATL","JFK","SFO","ATL","SFO"]
	}
	{
		vector<vector<string>> tickets = {{"JFK", "MUC"}};
		auto a = s.findItinerary(tickets);
		print(a); // answer: ["JFK","MUC"]
	}
	{
		vector<vector<string>> tickets = {{"JFK", "MUC"},{"MUC", "JFK"}};
		auto a = s.findItinerary(tickets);
		print(a); // answer: ["JFK","MUC","JFK"]
	}
	{
		vector<vector<string>> tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
		auto a = s.findItinerary(tickets);
		print(a); // answer: ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
	}
	return 0;
}
