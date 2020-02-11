// https://leetcode-cn.com/problems/reorder-list/
#include <cstdio>
#include <initializer_list>
#include <vector>
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
    void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		vector<ListNode*> a;
		for (ListNode* p = head; p; p = p->next) {
			a.push_back(p);
		}
		int n = a.size();
		int i = 0, j = n - 1;
		for (; i < j; ++i, --j) {
			a[i]->next = a[j];
			a[j]->next = a[i + 1];
		}
		a[i]->next = NULL;
    }
};

int main()
{
	Solution s;
	{
		ListNode* p = init({1,2,3,4});
		print(p);
		s.reorderList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = init({1,2,3,4,5});
		print(p);
		s.reorderList(p);
		print(p);
		release(p);
	}
	{
		ListNode* p = NULL;
		print(p);
		s.reorderList(p);
		print(p);
		release(p);
	}
	return 0;
}
