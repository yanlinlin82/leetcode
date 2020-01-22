// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		for (ListNode* p = head; p;) {
			if (p->next && p->val == p->next->val) {
				ListNode* next = p->next->next;
				delete p->next;
				p->next = next;
			} else {
				p = p->next;
			}
		}
		return head;
	}
};

int main()
{
	Solution s;
	{
		ListNode* p = init({1,2,3,3,4,4,5});
		p = s.deleteDuplicates(p);
		print(p); // answer: [1,2,5]
		release(p);
	}
	{
		ListNode* p = init({1,1,1,2,3});
		p = s.deleteDuplicates(p);
		print(p); // answer: [2,3]
		release(p);
	}
	{
		ListNode* p = init({});
		p = s.deleteDuplicates(p);
		print(p); // answer: []
		release(p);
	}
	{
		ListNode* p = init({1,1});
		p = s.deleteDuplicates(p);
		print(p); // answer: []
		release(p);
	}
	return 0;
}
