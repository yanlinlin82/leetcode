// https://leetcode-cn.com/problems/partition-list/
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
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) return head;
		ListNode a(0), b(0);
		ListNode* pa = &a;
		ListNode* pb = &b;
		for (ListNode *p = head, *next = head->next; p; p = next, next = (next ? next->next : NULL)) {
			p->next = NULL;
			if (p->val < x) {
				pa->next = p; pa = p;
			} else {
				pb->next = p; pb = p;
			}
		}
		pa->next = b.next;
		return a.next;
	}
};

int main()
{
	Solution s;
	{
		ListNode* p = init({1,4,3,2,5,2});
		p = s.partition(p, 3);
		print(p); // answer: 1->2->2->4->3->5
		release(p);
	}
	return 0;
}
