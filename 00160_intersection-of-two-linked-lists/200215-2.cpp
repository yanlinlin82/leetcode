// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
#include <cstdio>
#include <initializer_list>
#include <unordered_set>
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode*> o;
		for (ListNode* p = headA; p; p = p->next) o.insert(p);
		for (ListNode* q = headB; q; q = q->next) {
			if (o.find(q) != o.end()) return q;
		}
		return NULL;
	}
};

int main()
{
	Solution s;
	{
		ListNode* a = init({4,1,8,4,5});
		ListNode* b = init({5,0,1});
		b->next->next->next = a->next->next;
		ListNode* c = s.getIntersectionNode(a, b);
		printf("%d\n", (c ? c->val : -1));
		b->next->next->next = NULL;
		release(b);
		release(a);
	}
	{
		ListNode* a = init({0,9,1,2,4});
		ListNode* b = init({3});
		b->next = a->next->next->next;
		ListNode* c = s.getIntersectionNode(a, b);
		printf("%d\n", (c ? c->val : -1));
		b->next = NULL;
		release(b);
		release(a);
	}
	{
		ListNode* a = init({2,6,4});
		ListNode* b = init({1,5});
		ListNode* c = s.getIntersectionNode(a, b);
		printf("%d\n", (c ? c->val : -1));
		release(b);
		release(a);
	}
	return 0;
}
