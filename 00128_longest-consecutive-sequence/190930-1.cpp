// https://leetcode-cn.com/problems/longest-consecutive-sequence/
#include <cstdio>
#include <vector>
#include <memory>
#include <utility>
using namespace std;

class Solution {
	vector<shared_ptr<pair<int,int>>> r; // start, end
	vector<vector<pair<int,int>>> hash; // key => [ {value, index}, ... ]
	int n;
public:
	int longestConsecutive(vector<int>& nums) {
		n = nums.size();
		if (n == 0) return 0;
		hash.resize(n);
		int longest = 1;
		for (int i = 0; i < n; ++i) {
			int key, j, minV, maxV;
			if (findNode(nums[i], key, j, minV, maxV)) continue; // skip if existed

			int keyL, jL, minL, maxL;
			if (findNode(nums[i] - 1, keyL, jL, minL, maxL)) {
				minV = minL;
			} else {
				minV = nums[i];
			}

			int keyR, jR, minR, maxR;
			if (findNode(nums[i] + 1, keyR, jR, minR, maxR)) {
				maxV = maxR;
			} else {
				maxV = nums[i];
			}

			int index = r.size();
			r.push_back(make_shared<pair<int,int>>(minV, maxV));
			j = hash[key].size();
			hash[key].push_back(make_pair(nums[i], index));

			if (minV < nums[i]) {
				int keyM, jM, minM, maxM;
				findNode(minV, keyM, jM, minM, maxM);
				r[hash[keyM][jM].second] = r[index];
			}
			if (maxV > nums[i]) {
				int keyM, jM, minM, maxM;
				findNode(maxV, keyM, jM, minM, maxM);
				r[hash[keyM][jM].second] = r[index];
			}

			int range = maxV - minV + 1;
			if (range > longest) {
				longest = range;
			}
		}
		return longest;
	}
private:
	bool findNode(int value, int& key, int& index, int& min, int& max)
	{
		key = value % n;
		if (key < 0) key += n;
		for(int j = 0; j < hash[key].size(); ++j) {
			if (hash[key][j].first == value) {
				index = j;
				auto p = r[hash[key][j].second];
				min = p->first;
				max = p->second;
				return true;
			}
		}
		index = -1;
		return false;
	}
};

int main()
{
	//vector<int> nums = { 0, 0 };                 // answer = 1
	//vector<int> nums = { 100, 4, 200, 1, 3, 2 }; // answer = 4
	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};      // answer = 9
	Solution s;
	printf("%d\n", s.longestConsecutive(nums));
	return 0;
}
