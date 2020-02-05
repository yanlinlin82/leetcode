// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

string to_string(Node* t) { return (t ? to_string(t->val) : "null"); }

void print(Node* t, string leading = "")
{
	cout << leading << to_string(t) << " -> ("
		<< to_string(t ? t->left : NULL) << ", "
		<< to_string(t ? t->right : NULL) << ", "
		<< to_string(t ? t->next : NULL) << ")"
		<< endl;
	if (t->left) print(t->left, leading + "  ");
	if (t->right) print(t->right, leading + "  ");
}

void release(Node* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

class Solution {
public:
	Node* connect(Node* root) {
		if (root) {
			connect(root->left);
			connect(root->right);
			Node* p = root->left;
			Node* q = root->right;
			while (p) {
				Node* p2 = p; while (p2->next) p2 = p2->next;
				Node* q2 = q;
				while (p && !p->left && !p->right) p = p->next;
				p = p ? (p->left ? p->left : p->right) : NULL;
				while (q && !q->left && !q->right) q = q->next;
				q = q ? (q->left ? q->left : q->right) : NULL;
				p2->next = q2;
			}
		}
		return root;
	}
};

int main()
{
	Solution s;
	{
		Node* t = new Node(1);
		t->left = new Node(2);
		t->right = new Node(3);
		t->left->left = new Node(4);
		t->left->right = new Node(5);
		t->right->right = new Node(7);
		t = s.connect(t);
		print(t);
		release(t);
	}
	{
		Node* t = new Node(0);
		t->left = new Node(2);
		t->right = new Node(4);
		t->left->left = new Node(1);
		t->right->left = new Node(3);
		t->right->right = new Node(-1);
		t->left->left->left = new Node(5);
		t->left->left->right = new Node(1);
		t->right->left->right = new Node(8);
		t = s.connect(t);
		print(t);
		release(t);
	}
	{
		Node* t = new Node(1);
		t->left = new Node(2);
		t->right = new Node(3);
		t->left->left = new Node(4);
		t->left->right = new Node(5);
		t->right->right = new Node(6);
		t->left->left->left = new Node(7);
		t->right->right->right = new Node(8);
		t = s.connect(t);
		print(t);
		release(t);
	}
	{
		Node* t = new Node(2);
		t->left = new Node(1);
		t->right = new Node(3);
		t->left->left = new Node(0);
		t->left->right = new Node(7);
		t->right->left = new Node(9);
		t->right->right = new Node(1);
		t->left->left->left = new Node(2);
		t->left->right->left = new Node(1);
		t->left->right->right = new Node(0);
		t->right->right->left = new Node(8);
		t->right->right->right = new Node(8);
		t->left->right->left = new Node(7);
		t = s.connect(t);
		print(t);
		release(t);
	}
	return 0;
}
