// https://leetcode-cn.com/problems/minimum-window-substring/
// 失败：未考虑字符串t有重复
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
		vector<vector<Node>> map;
		for (int i = 0; i < m; ++i) {
			if (order.find(t[i]) == order.end()) {
				order[t[i]] = map.size();
				map.push_back(vector<Node>());
			}
		}
		if (order.empty()) return "";
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			auto it = order.find(c);
			if (it != order.end()) {
				int index = it->second;
				map[index].push_back(Node(i));
			}
		}
		for (int i = 0; i < map.size(); ++i) {
			if (i == 0) {
				for (int j = 0; j < map[i].size(); ++j) {
					map[i][j].start = map[i][j].end = map[i][j].index;
				}
			} else {
				for (int j = 0; j < map[i].size(); ++j) {
					int index = map[i][j].index;
					int min_size = 0;
					for (int k = 0; k < map[i - 1].size(); ++k) {
						int a = min(map[i - 1][k].start, index);
						int b = max(map[i - 1][k].end, index);
						int size = b - a + 1;
						if (min_size == 0 || size < min_size) {
							min_size = size;
							map[i][j].start = a;
							map[i][j].end = b;
						}
					}
				}
			}
		}
		int min_size = 0;
		int start = -1;
		int end = -1;
		const auto& res = map.back();
		for (int i = 0; i < res.size(); ++i) {
			int size = res[i].end - res[i].start + 1;
			if (min_size == 0 || size < min_size) {
				min_size = size;
				start = res[i].start;
				end = res[i].end;
			}
		}
		if (min_size == 0) {
			return "";
		}
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
