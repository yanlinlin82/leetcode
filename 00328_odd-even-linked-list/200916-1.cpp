// https://leetcode-cn.com/problems/odd-even-linked-list/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* init(initializer_list<int>&& a)
{
	ListNode node(0);
	ListNode* p = &node;
	for (auto it = a.begin(); it != a.end(); ++it) {
		p->next = new ListNode(*it);
		p = p->next;
	}
	return node.next;
}

void print(ListNode* l)
{
	for (ListNode* p = l; p; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

void release(ListNode* p)
{
	if (p) {
		release(p->next);
		delete p;
	}
}

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *a = NULL, *a2 = NULL, *b = NULL, *b2 = NULL;
		int i = 0;
		for (ListNode* p = head; p; p = p->next, ++i) {
			if (i % 2 == 0) {
				if (!a) {
					a = a2 = p;
				} else {
					a2->next = p;
					a2 = p;
				}
			} else {
				if (!b) {
					b = b2 = p;
				} else {
					b2->next = p;
					b2 = p;
				}
			}
		}
		a2->next = b;
		b2->next = NULL;
		return a;
	}
};

int main()
{
	Solution s;
	{
		ListNode* p = init({1,2,3,4,5});
		print(p); // origin: 1->2->3->4->5->NULL
		s.oddEvenList(p);
		print(p); // answer: 1->3->5->2->4->NULL
		release(p);
	}
	{
		ListNode* p = init({2,1,3,5,6,4,7});
		print(p); // origin: 2->1->3->5->6->4->7->NULL
		s.oddEvenList(p);
		print(p); // answer: 2->3->6->7->1->5->4->NULL
		release(p);
	}
	return 0;
}
