// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode sentinel(0);
		sentinel.next = head;
		vector<ListNode*> nodes(k);
		ListNode* p = &sentinel;
		for (;;) {
			ListNode* next = process(p, k, &nodes[0]);
			if (!next) break;
			p = next;
		}
		return sentinel.next;
	}
private:
	ListNode* process(ListNode* prev, int k, ListNode** buffer) {
		ListNode* p = prev->next;
		for (int i = 0; i < k; ++i) {
			if (!p) return NULL;
			buffer[i] = p;
			p = p->next;
		}
		buffer[0]->next = buffer[k - 1]->next;
		for (int i = 1; i < k; ++i) {
			buffer[i]->next = buffer[i - 1];
		}
		prev->next = buffer[k - 1];
		return buffer[0];
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
	{
		ListNode* l = create({1, 2, 3, 4, 5});
		print(l);
		l = s.reverseKGroup(l, 2);
		print(l); // answer: 2->1->4->3->5
		destroy(l);
	}
	{
		ListNode* l = create({1, 2, 3, 4, 5});
		print(l);
		l = s.reverseKGroup(l, 3);
		print(l); // answer: 3->2->1->4->5
		destroy(l);
	}
	return 0;
}
