// https://leetcode-cn.com/problems/linked-list-cycle/
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
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode* p = head;
		ListNode* q = head->next;
		while (p != q) {
			p = (p ? p->next : NULL);
			q = (q ? q->next : NULL); q = (q ? q->next : NULL);
		}
		return (p != NULL);
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
		printf("%d\n", s.hasCycle(n0)); // answer: true
		release(n0);
	}
	{
		ListNode* n0 = new ListNode(1);
		ListNode* n1 = new ListNode(2);
		n0->next = n1;
		n1->next = n0; // pos = 0
		printf("%d\n", s.hasCycle(n0)); // answer: true
		release(n0);
	}
	{
		ListNode* n0 = new ListNode(1);
		; // pos = -1
		printf("%d\n", s.hasCycle(n0)); // answer: false
		release(n0);
	}
	return 0;
}

