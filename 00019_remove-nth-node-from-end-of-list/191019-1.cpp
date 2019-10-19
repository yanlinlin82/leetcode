// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* p, const char* prefix = "", const char* suffix = "*\n")
{
	printf("%s", prefix);
	if (p) {
		printf("%d", p->val);
		print(p->next, " -> ", "");
	}
	printf("%s", suffix);
}

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n <= 0 || head == NULL) return head;
		ListNode* p = head;
		for (int i = 0; i < n; ++i) {
			if (p == NULL) { // n is too large, do not remove anything
				return head;
			}
			p = p->next;
		}
		if (p == NULL) { // remove the first
			ListNode* r = head->next;
			delete head;
			return r;
		} else {
			ListNode* q = head;
			p = p->next;
			while (p) {
				p = p->next;
				q = q->next;
			}
			p = q->next;
			q->next = q->next->next;
			delete p;
			return head;
		}
	}
};

void release(ListNode* p)
{
	if (p) {
		release(p->next);
		delete p;
	}
}

ListNode* create(int n)
{
	ListNode* p = NULL;
	for (int i = n; i > 0; --i) {
		ListNode* q = new ListNode(i);
		q->next = p;
		p = q;
	}
	return p;
}

int main() {
	Solution s;

	{
		printf("============ remove(2)\n");
		ListNode* p = create(5);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 2);
		print(p, "after:  "); // answer: 1 -> 2 -> 3 -> 5
		release(p);
	}

	{
		printf("============ remove(1)\n");
		ListNode* p = create(1);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 1);
		print(p, "after:  "); // answer: null
		release(p);
	}

	{
		printf("============ remove(0)\n");
		ListNode* p = create(1);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 0);
		print(p, "after:  "); // answer: 1
		release(p);
	}

	{
		printf("============ remove(1)\n");
		ListNode* p = create(1);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 1);
		print(p, "after:  "); // answer: null
		release(p);
	}

	{
		printf("============ remove(0)\n");
		ListNode* p = create(2);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 0);
		print(p, "after:  "); // answer: 1 -> 2
		release(p);
	}

	{
		printf("============ remove(1)\n");
		ListNode* p = create(2);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 1);
		print(p, "after:  "); // answer: 1
		release(p);
	}

	{
		printf("============ remove(2)\n");
		ListNode* p = create(2);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 2);
		print(p, "after:  "); // answer: 2
		release(p);
	}

	{
		printf("============ remove(3)\n");
		ListNode* p = create(2);
		print(p, "before: ");
		p = s.removeNthFromEnd(p, 3);
		print(p, "after:  "); // answer: 1 -> 2
		release(p);
	}

	return 0;
}
