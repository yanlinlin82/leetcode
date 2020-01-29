// https://leetcode-cn.com/problems/reverse-linked-list-ii/
#include <cstdio>
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(initializer_list<int> a) {
	ListNode node(0);
	ListNode* p = &node;
	for (auto e : a) {
		p->next = new ListNode(e);
		p = p->next;
	}
	return node.next;
}

void release(ListNode* p) {
	if (p) release(p->next);
	delete p;
}

void print(ListNode* p, bool hasEndl = true) {
	if (p) {
		printf("%d ", p->val);
		if (p->next) print(p->next, false);
	}
	if (hasEndl) printf("\n");
}

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode node(0);
		node.next = head;
		ListNode* p = &node;
		for (int i = 1; i < m; ++i) p = p->next;
		ListNode* a = p;
		ListNode* b = p->next;
		a->next = NULL;
		p = b;
		for (int i = m; i <= n; ++i) {
			ListNode* next = p->next;
			p->next = a->next;
			a->next = p;
			p = next;
		}
		b->next = p;
		return node.next;
	}
};

int main()
{
	Solution s;
	{
		ListNode* p = init({1,2,3,4,5});
		p = s.reverseBetween(p, 2, 4);
		print(p);
		release(p); // answer: 1->4->3->2->5->NULL
	}
	{
		ListNode* p = init({1,2,3,4,5});
		p = s.reverseBetween(p, 1, 5);
		print(p);
		release(p); // answer: 5->4->3->2->1->NULL
	}
	{
		ListNode* p = init({1,2,3,4,5});
		p = s.reverseBetween(p, 2, 3);
		print(p);
		release(p); // answer: 5->4->3->2->1->NULL
	}
	{
		ListNode* p = init({1});
		p = s.reverseBetween(p, 1, 1);
		print(p);
		release(p); // answer: 5->4->3->2->1->NULL
	}
	return 0;
}
