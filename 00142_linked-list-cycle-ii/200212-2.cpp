// https://leetcode-cn.com/problems/linked-list-cycle-ii/
// 进阶：使用常量内存（快慢指针法）
#include <cstdio>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return NULL;
		ListNode* p = head;
		ListNode* q = head->next;
		while (p != q) {
			p = (p ? p->next : NULL);
			q = (q ? q->next : NULL); q = (q ? q->next : NULL);
		}
		if (!p) return NULL;
		ListNode* tail = p;
		for (p = head; p != tail; p = p->next) {
			for (q = tail->next; q != tail; q = q->next) {
				if (q == p) return p;
			}
		}
		return p;
	}
};

void release(ListNode* t)
{
	unordered_set<ListNode*> s;
	ListNode* p = t;
	for (; p && s.find(p) == s.end(); p = p->next) {
		s.insert(p);
	}
	for (auto e : s) delete e;
}

int main()
{
	Solution s;
	{
		ListNode* n0 = new ListNode(3);
		ListNode* n1 = new ListNode(2);
		ListNode* n2 = new ListNode(0);
		ListNode* n3 = new ListNode(-4);
		n0->next = n1; n1->next = n2; n2->next = n3;
		n3->next = n1; // pos = 1
		ListNode* p = s.detectCycle(n0);
		if (p) printf("%d\n", p->val); else printf("null\n"); // answer: 2
		release(n0);
	}
	{
		ListNode* n0 = new ListNode(1);
		ListNode* n1 = new ListNode(2);
		n0->next = n1;
		n1->next = n0; // pos = 0
		ListNode* p = s.detectCycle(n0);
		if (p) printf("%d\n", p->val); else printf("null\n"); // answer: 1
		release(n0);
	}
	{
		ListNode* n0 = new ListNode(1);
		; // pos = -1
		ListNode* p = s.detectCycle(n0);
		if (p) printf("%d\n", p->val); else printf("null\n"); // answer: null
		release(n0);
	}
	return 0;
}
