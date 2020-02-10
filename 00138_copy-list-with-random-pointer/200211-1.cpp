// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return NULL;
		unordered_map<Node*, Node*> m;
		Node* t = new Node(head->val);
		m[head] = t;
		for (Node *p = t, *q = head; q->next; p = p->next, q = q->next) {
			p->next = new Node(q->next->val);
			m[q->next] = p->next;
		}
		for (Node *p = t, *q = head; q; p = p->next, q = q->next) {
			p->random = q->random ? m[q->random] : NULL;
		}
		return t;
	}
};

void print(Node* t)
{
	unordered_map<Node*, int> m;
	int c = 0;
	for (Node* p = t; p; p = p->next) m[p] = c++;
	printf("[");
	for (Node* p = t; p; p = p->next) {
		printf("[%d,", p->val);
		if (p->random) printf("%d", m[p->random]); else printf("null");
		printf("]");
	}
	printf("]\n");
}

void release(Node* t)
{
	if (t) {
		if (t->next) release(t->next);
		delete t;
	}
}

int main()
{
	Solution s;
	{
		Node* t0 = new Node(7);
		Node* t1 = new Node(13); 
		Node* t2 = new Node(11); 
		Node* t3 = new Node(10); 
		Node* t4 = new Node(1); 
		t0->next = t1; t1->next = t2; t2->next = t3; t3->next = t4;
		t1->random = t0; t2->random = t4; t3->random = t2; t4->random = t0; 
		print(t0);
		Node* p = s.copyRandomList(t0);
		print(p);
		release(p);
		release(t0);
	}
	{
		Node* t0 = new Node(1);
		Node* t1 = new Node(2); 
		t0->next = t1;
		t1->random = t1;
		print(t0);
		Node* p = s.copyRandomList(t0);
		print(p);
		release(p);
		release(t0);
	}
	{
		Node* t0 = new Node(3);
		Node* t1 = new Node(3); 
		Node* t2 = new Node(3); 
		t0->next = t1; t1->next = t2;
		t1->random = t0;
		print(t0);
		Node* p = s.copyRandomList(t0);
		print(p);
		release(p);
		release(t0);
	}
	{
		Node* t0 = NULL;
		print(t0);
		Node* p = s.copyRandomList(t0);
		print(p);
		release(p);
		release(t0);
	}
	return 0;
}
