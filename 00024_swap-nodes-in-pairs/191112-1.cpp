// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* p)
{
	for (; p; p = p->next) {
		printf("%d ", p->val);
	}
	printf("\n");
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode node(0);
		node.next = head;
		ListNode* p = &node;
		ListNode* q = head;
		while (q && q->next) {
			ListNode* tmp = p->next;
			p->next = q->next;
			q->next = p->next->next;
			p->next->next = tmp;
			p = q;
			q = q->next;
		}
		return node.next;
	}
};

ListNode* create(initializer_list<int> a)
{
	ListNode* list = NULL;
	ListNode* prev = NULL;
	for (auto it = a.begin(); it != a.end(); ++it) {
		ListNode* p = new ListNode(*it);
		if (prev == NULL) {
			list = p;
			prev = p;
		} else {
			prev->next = p;
			prev = p;
		}
	}
	return list;
}

void destroy(ListNode* p)
{
	while (p) {
		ListNode* next = p->next;
		delete p;
		p = next;
	}
}

int main()
{
	Solution s;
	ListNode* l = create({1, 2, 3, 4});
	print(l);
	l = s.swapPairs(l);
	print(l);
	destroy(l);
	return 0;
}
