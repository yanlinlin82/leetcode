// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
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
		if (root && root->left && root->right) {
			connect(root->left);
			connect(root->right);
			Node* p = root->left;
			Node* q = root->right;
			while (p && q) {
				p->next = q;
				p = p->right;
				q = q->left;
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
		t->right->left = new Node(6);
		t->right->right = new Node(7);
		t = s.connect(t);
		print(t);
		release(t);
	}
	return 0;
}
