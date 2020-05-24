// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node && node->next) {
			ListNode* p = node->next;
			node->val = node->next->val;
			node->next = node->next->next;
			delete p;
		}
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
		ListNode* p = init({4,5,1,9});
		print(p);
		s.deleteNode(p->next);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({4,5,1,9});
		print(p);
		s.deleteNode(p->next->next);
		print(p);
		release(p);
	}
	return 0;
}
