// https://leetcode-cn.com/problems/bulls-and-cows/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0;
		for (int i = 0; i < secret.size() && i < guess.size(); ++i) {
			if (secret[i] == guess[i]) {
				++bulls;
			}
		}
		unordered_map<char, int> m;
		for (auto c : secret) {
			++m[c];
		}
		int all = 0;
		for (auto c : guess) {
			auto it = m.find(c);
			if (it != m.end()) {
				if (it->second > 0) {
					--it->second;
					++all;
				}
			}
		}
		int cows = all - bulls;
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

int main()
{
	Solution s;
	cout << s.getHint("1807", "7810") << endl; // answer: "1A3B"
	cout << s.getHint("1123", "0111") << endl; // answer: "1A1B"
	return 0;
}
