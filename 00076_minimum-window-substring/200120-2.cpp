// https://leetcode-cn.com/problems/minimum-window-substring/
// 失败：动态规划方法并不合适，子问题最优解并不能确保问题最优解
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
	int index, start, end;
	explicit Node(int i): index(i), start(-1), end(-1) { }
};

class Solution {
public:
	string minWindow(string s, string t) {
		int n = s.size();
		int m = t.size();
		unordered_map<char, int> order;
		vector<pair<int, vector<Node>>> map; // [count, nodes]
		for (int i = 0; i < m; ++i) {
			auto it = order.find(t[i]);
			if (it == order.end()) {
				order[t[i]] = map.size();
				map.push_back(make_pair(0, vector<Node>()));
			} else {
				int index = it->second;
				map[index].first++;
			}
		}
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			auto it = order.find(c);
			if (it != order.end()) {
				int index = it->second;
				map[index].second.push_back(Node(i));
			}
		}
		for (int i = 0; i < map.size(); ++i) {
			if (map[i].second.size() <= map[i].first) {
				return "";
			}
		}
		for (int i = 0; i < map.size(); ++i) {
			if (i == 0) {
				for (int j = map[i].first; j < map[i].second.size(); ++j) {
					map[i].second[j].start = map[i].second[j - map[i].first].index;
					map[i].second[j].end = map[i].second[j].index;
				}
			} else {
				for (int j = map[i].first; j < map[i].second.size(); ++j) {
					int index1 = map[i].second[j - map[i].first].index;
					int index2 = map[i].second[j].index;
					int min_size = 0;
					for (int k = map[i - 1].first; k < map[i - 1].second.size(); ++k) {
						int a = min(map[i - 1].second[k].start, index1);
						int b = max(map[i - 1].second[k].end, index2);
						int size = b - a + 1;
						if (min_size == 0 || size < min_size) {
							min_size = size;
							map[i].second[j].start = a;
							map[i].second[j].end = b;
						}
					}
				}
			}
			//print(map);
		}
		int min_size = 0;
		int start = -1;
		int end = -1;
		const auto& r = map.back();
		for (int i = r.first; i < r.second.size(); ++i) {
			int size = r.second[i].end - r.second[i].start + 1;
			if (min_size == 0 || size < min_size) {
				min_size = size;
				start = r.second[i].start;
				end = r.second[i].end;
			}
		}
		//printf("{%d,%d,%d}\n", min_size, start, end);
		return s.substr(start, end - start + 1);
	}
};

int main()
{
	Solution s;
	printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str()); // answer: "BANC"
	printf("%s\n", s.minWindow("a", "aa").c_str()); // answer: "a"
	printf("%s\n", s.minWindow("aba", "aa").c_str()); // answer: "aba"
	printf("%s\n", s.minWindow("abaa", "aa").c_str()); // answer: "aa"
	printf("%s\n", s.minWindow("aaabaabab", "aab").c_str()); // answer: "aab"
	printf("%s\n", s.minWindow("cabefgecdaecf", "cae").c_str()); // answer: "ace"
	printf("%s\n", s.minWindow("b..a...cb....a.b", "abc").c_str()); // answer: "a...cb"
	printf("%s\n", s.minWindow("a", "b").c_str()); // answer: ""
	printf("%s\n", s.minWindow("a", "ab").c_str()); // answer: ""
	printf("%s\n", s.minWindow("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country", "ask_country").c_str()); // answer: "sk_not_what_your_countr"
	printf("%s\n", s.minWindow("cabwefgewcwaefgcf", "cae").c_str()); // answer: "cwae"
	printf("%s\n", s.minWindow("", "").c_str()); // answer: ""
	printf("%s\n", s.minWindow("qdsvbyuipqxnhkbgqdgozelvapgcainsofnrfjzvawihgmpwpwnqcylcnufqcsiqzwhhhjchfmqmagkrexigytklnrdslmkniuurdwzikrwlxhcbgkjegwsvnvpzhamrwgjzekjobizbreexqqewmwubtjadlowhwhiarurvcsyvwcunsylgwhisrivezrmvzwwsqppuhnreqmtkkgrjozbhjwlkpzgqwejotylamcgeqzobihmwinduloecqmtoqcejcpmqusukulncsbabodxbtbeloxzgbesdveupyocuzryutyxjdulzvpklokspqkslqodqfhlgajatkxfntqorhzcxlwmdigoyxtrcccidnlyxidnevdveczbpwpugyjhveyxhcfkpqipboehjhcombrdzhyghjncnnzwpggezrvcfzjqjngvoyyqhwwohlsvarrpzavatrcasnqbazyrzxhivfydsqasjtjiteloxposdhtfgswhrfpomnteftyonjyiojxnznfeubjctijmnyaanwgsphieqhpgsoutbbxycjaxrklekogakpsbwdimkxvelpyosvmxgnuxzgejwmjgbehxhpmtohzbyxqsvepbrmzsufcqrnwttfscxgxlpxnpufirjxtdjuvfzzvqprlizelwmkjchwtcdbvpbosminsjpncehnmgtzegknkrmdvrhrgihywsoobdedhltvtmxzuhmeaakysrpybyzxqnouqszzfswahtzbanidoubilsgoqfnjubdmvclaxkaedbfeppj", "fjknwevk").c_str()); // answer: ""
	printf("%s\n", s.minWindow("abcabdebac", "cda").c_str()); // answer: "cabd"
	return 0;
}
