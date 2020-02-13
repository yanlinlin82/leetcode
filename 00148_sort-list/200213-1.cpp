// https://leetcode-cn.com/problems/sort-list/
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

void print(ListNode* p) {
	printf("[ "); for (; p; p = p->next) printf("%d ", p->val); printf("]\n");
}

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		int n = 0;
		for (ListNode* p = head; p; p = p->next) ++n;
		ListNode* p = head;
		for (int i = 0; i + 1 < n / 2; ++i) p = p->next;
		ListNode* q = p->next;
		p->next = NULL;
		p = head;
		p = sortList(p);
		q = sortList(q);
		ListNode node(0);
		ListNode* curr = &node;
		for (;;) {
			if (p && q) {
				if (p->val <= q->val) {
					curr->next = p;
					p = p->next;
					curr = curr->next;
				} else {
					curr->next = q;
					q = q->next;
					curr = curr->next;
				}
			} else if (p) {
				curr->next = p;
				p = p->next;
				curr = curr->next;
			} else if (q) {
				curr->next = q;
				q = q->next;
				curr = curr->next;
			} else {
				break;
			}
		}
		return node.next;
	}
};

int main()
{
	Solution s;
	{
		ListNode* p = init({4,2,1,3});
		print(p);
		p = s.sortList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({-1,5,3,4,0});
		print(p);
		p = s.sortList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({});
		print(p);
		p = s.sortList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({1});
		print(p);
		p = s.sortList(p);
		print(p);
		release(p);
	}
	return 0;
}
