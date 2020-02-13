// https://leetcode-cn.com/problems/insertion-sort-list/
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
	printf("[ "); for (; p; p = p->next) printf("%d ", p->val); printf("]\n");
}

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode node(0); node.next = head;
		for (;;) {
			ListNode* s = NULL;
			for (ListNode* p = &node; p->next; p = p->next) {
				if (p != &node && p->val > p->next->val) {
					s = p->next;
					p->next = p->next->next;
					break;
				}
			}
			if (!s) break;
			for (ListNode* p = &node; p->next; p = p->next) {
				if (p->next->val >= s->val) {
					s->next = p->next;
					p->next = s;
					break;
				}
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
		p = s.insertionSortList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({-1,5,3,4,0});
		print(p);
		p = s.insertionSortList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({});
		print(p);
		p = s.insertionSortList(p);
		print(p);
		release(p);
	}
	return 0;
}
