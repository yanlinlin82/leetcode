// https://leetcode-cn.com/problems/integer-to-english-words/
// 解答错误：101 => "One Hundred One"（而非"One Hundred And One"）
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		static const char* WORDS[] = {
			"Zero", "One", "Two", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
			"Sixteen", "Seventeen", "Eighteen", "Nineteen"
		};
		static const char* WORDS2[] = {
			"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
		};
		string s;
		if (num < 20) {
			s = WORDS[num];
		} else if (num < 100) {
			s = WORDS2[num / 10 - 2];
			if (num % 10 > 0) {
				s += " " + numberToWords(num % 10);
			}
		} else if (num < 1000) {
			s = WORDS[num / 100];
			s += " Hundred";
			if (num % 100 > 0) {
				s += " ";
				if (num % 100 < 10) {
					s += "And ";
				}
				s += numberToWords(num % 100);
			}
		} else if (num < 1000000) {
			s = numberToWords(num / 1000);
			s += " Thousand";
			if (num % 1000 > 0) {
				s += " ";
				if (num % 1000 < 100) {
					s += "And ";
				}
				s += numberToWords(num % 1000);
			}
		} else if (num < 1000000000) {
			s = numberToWords(num / 1000000);
			s += " Million";
			if (num % 1000 > 0) {
				s += " ";
				if (num % 1000000 < 100000) {
					s += "And ";
				}
				s += numberToWords(num % 1000000);
			}
		} else {
			s = numberToWords(num / 1000000000);
			s += " Billion";
			if (num % 1000000000 > 0) {
				s += " ";
				if (num % 1000000000 < 100000000) {
					s += "And ";
				}
				s += numberToWords(num % 1000000000);
			}
		}
		return s;
	}
};

int main()
{
	Solution s;
	for (int i = 0; i <= 21; ++i) {
		cout << s.numberToWords(i) << endl;
	}
	cout << s.numberToWords(123) << endl; // answer: "One Hundred Twenty Three"
	cout << s.numberToWords(12345) << endl; // answer: "Twelve Thousand Three Hundred Forty Five"
	cout << s.numberToWords(1234567) << endl; // answer: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
	cout << s.numberToWords(1234567891) << endl; // answer: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
	return 0;
}
