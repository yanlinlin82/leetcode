// https://leetcode-cn.com/problems/remove-linked-list-elements/
#include <iostream>
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode node(0);
		node.next = head;
		for (ListNode* p = &node; p->next;) {
			if (p->next->val == val) {
				ListNode* q = p->next;
				p->next = p->next->next;
				delete q;
			} else {
				p = p->next;
			}
		}
		return node.next;
	}
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

int main()
{
	Solution s;
	{
		ListNode* l = init({1,2,6,3,4,5,6});
		print(l);
		s.removeElements(l, 6);
		print(l);
		release(l);
	}
	return 0;
}
