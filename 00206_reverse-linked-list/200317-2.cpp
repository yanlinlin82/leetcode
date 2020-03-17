// https://leetcode-cn.com/problems/reverse-linked-list/
// 迭代法
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* q = NULL;
		for (ListNode* p = head; p;) {
			ListNode* next = p->next;
			p->next = q;
			q = p;
			p = next;
		}
		return q;
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
		ListNode* p = init({1,2,3,4,5});
		print(p);
		p = s.reverseList(p);
		print(p);
		release(p);
	}
	return 0;
}
