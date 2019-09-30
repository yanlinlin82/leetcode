// https://leetcode-cn.com/problems/add-two-numbers/
#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode tmp(0);
		ListNode* p = &tmp;
		bool carry = false;
		while (l1 || l2) {
			int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = (value >= 10);
			ListNode* n = new ListNode(value % 10);
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
			p->next = n;
			p = n;
		}
		if (carry) {
			p->next = new ListNode(1);
		}
		return tmp.next;
	}
};

void Print(ListNode* p)
{
	printf("%d", p->val);
	while (p->next) {
		p = p->next;
		printf(" -> %d", p->val);
	}
	printf("\n");
}

void Release(ListNode* p)
{
	ListNode* q;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
}

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3); // (2 -> 4 -> 3)

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4); // (5 -> 6 -> 4)

	Solution s;
	ListNode* r = s.addTwoNumbers(l1, l2);

	Print(r);
	Release(r);
	Release(l2);
	Release(l1);
	return 0;
}
