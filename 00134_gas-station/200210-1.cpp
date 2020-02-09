// https://leetcode-cn.com/problems/gas-station/
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; ++i) {
			if (gas[i] < cost[i]) continue;
			int s = gas[i] - cost[i];
			int k = (i + 1) % n;
			for (; k != i; k = (k + 1) % n) {
				if (s + gas[k] < cost[k]) break;
				s += gas[k] - cost[k];
			}
			if (k == i) return i;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	{
		vector<int> gas = {1,2,3,4,5};
		vector<int> cost = {3,4,5,1,2};
		printf("%d\n", s.canCompleteCircuit(gas, cost)); // answer: 3
	}
	{
		vector<int> gas = {2,3,4};
		vector<int> cost = {3,4,3};
		printf("%d\n", s.canCompleteCircuit(gas, cost)); // answer: -1
	}
	return 0;
}
