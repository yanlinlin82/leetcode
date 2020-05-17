// https://leetcode-cn.com/problems/palindrome-linked-list/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> a;
		for (ListNode* p = head; p; p = p->next) {
			a.push_back(p->val);
		}
		for (int i = 0, j = a.size() - 1; i < j; ++i, --j) {
			if (a[i] != a[j]) return false;
		}
		return true;
	}
};

ListNode* init(initializer_list<int>&& a)
{
	ListNode node(0);
	ListNode* p = &node;
	for (auto it = a.begin(); it != a.end(); ++it) {
		p->next = new ListNode(*it);
		p = p->next;
	}
	return node.next;
}

void print(ListNode* l)
{
	for (ListNode* p = l; p; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

void release(ListNode* p)
{
	if (p) {
		release(p->next);
		delete p;
	}
}


int main()
{
	Solution s;
	{
		ListNode* p = init({1,2});
		print(p);
		cout << s.isPalindrome(p) << endl; // answer: false
		release(p);
	}
	{
		ListNode* p = init({1,2,2,1});
		print(p);
		cout << s.isPalindrome(p) << endl; // answer: true
		release(p);
	}
	return 0;
}
