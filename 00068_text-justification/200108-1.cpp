// https://leetcode-cn.com/problems/text-justification/
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int start = 0;
		vector<vector<string>> line_words;
		vector<int> width;
		for (int i = 0; i < words.size();) {
			if (i == start) {
				line_words.push_back(vector<string>{words[i]});
				width.push_back(words[i].size());
				++i;
			} else if (width.back() + 1 + words[i].size() <= maxWidth) {
				line_words.back().push_back(words[i]);
				width.back() += 1 + words[i].size();
				++i;
			} else {
				start = i;
			}
		}
		vector<string> res;
		for (int i = 0; i < line_words.size(); ++i) {
			int total_space_count = maxWidth - width[i];
			int word_count = line_words[i].size();
			int each_space_count = 0;
			int rest_spaces = 0;
			if (i + 1 < line_words.size() && word_count > 1) {
				each_space_count = total_space_count / (word_count - 1);
				rest_spaces = total_space_count - each_space_count * (word_count - 1);
			}
			string line;
			for (int j = 0; j < line_words[i].size(); ++j) {
				if (j > 0) {
					line += string(each_space_count + (j <= rest_spaces ? 2 : 1), ' ');
				}
				line += line_words[i][j];
			}
			if (line.size() < maxWidth) {
				line += string(maxWidth - line.size(), ' ');
			}
			res.push_back(line);
		}
		return res;
	}
};

void print(const vector<string>& a)
{
	printf("[\n");
	for (const auto& e : a) {
		printf("   \"%s\"\n", e.c_str());
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		vector<string> w = {"This", "is", "an", "example", "of", "text", "justification."};
		print(s.fullJustify(w, 16));
		// answer: 
		// [
		//    "This    is    an",
		//    "example  of text",
		//    "justification.  "
		// ]
	}
	{
		vector<string> w = {"What","must","be","acknowledgment","shall","be"};
		print(s.fullJustify(w, 16));
		// answer: 
		// [
		//    "What   must   be",
		//    "acknowledgment  ",
		//    "shall be        "
		// ]
	}
	{
		vector<string> w = {
			"Science","is","what","we","understand","well","enough","to","explain",
			"to","a","computer.","Art","is","everything","else","we","do"
		};
		print(s.fullJustify(w, 20));
		// answer: 
		// [
		//    "Science  is  what we",
		//    "understand      well",
		//    "enough to explain to",
		//    "a  computer.  Art is",
		//    "everything  else  we",
		//    "do                  "
		// ]
	}
	return 0;
}
