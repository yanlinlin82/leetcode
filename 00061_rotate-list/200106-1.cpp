// https://leetcode-cn.com/problems/rotate-list/
#include <cstdio>
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || k == 0) return head;
		int n = 1;
		ListNode* p = head;
		for (; p->next; p = p->next) ++n; // query list size, and get tail
		if (n <= 1) return head;
		p->next = head; // circulate the link list
		for (int i = 0; i < n - (k % n); ++i) { // found break point
			p = p->next;
		}
		head = p->next;
		p->next = NULL; // break it
		return head;
	}
};

ListNode* init(const initializer_list<int>& a)
{
	ListNode n(0);
	ListNode* p = &n;
	for (auto e : a) {
		p->next = new ListNode(e);
		p = p->next;
	}
	return n.next;
}

void print(const ListNode* n)
{
	for (const ListNode* p = n; p; p = p->next) {
		printf("%d ", p->val);
	}
	printf("\n");
}

void release(ListNode* n)
{
	if (n) {
		release(n->next);
		delete n;
	}
}

int main()
{
	Solution s;
	{
		ListNode* p = init({1, 2, 3, 4, 5});
		print(p);
		p = s.rotateRight(p, 2);
		print(p); // answer: 4, 5, 1, 2, 3
		release(p);
	}
	{
		ListNode* p = init({0, 1, 2});
		print(p);
		p = s.rotateRight(p, 4);
		print(p); // answer: 2, 0, 1
		release(p);
	}
	{
		ListNode* p = init({1, 2});
		print(p);
		p = s.rotateRight(p, 0);
		print(p); // answer: 1, 2
		release(p);
	}
	{
		ListNode* p = init({1, 2});
		print(p);
		p = s.rotateRight(p, 1);
		print(p); // answer: 2, 1
		release(p);
	}
	return 0;
}
