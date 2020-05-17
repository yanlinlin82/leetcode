// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val >= p->val && root->val <= q->val) {
			return root;
		} else if (root->val <= p->val && root->val >= q->val) {
			return root;
		} else if (root->val >= p->val && root->val >= q->val) {
			return lowestCommonAncestor(root->left, p, q);
		} else {
			return lowestCommonAncestor(root->right, p, q);
		}
	}
};

void print(TreeNode* t, bool endl = true)
{
	if (t) {
		cout << "(" << t->val;
		if (t->left || t->right) {
			cout << ", ";
			if (t->left) {
				print(t->left, false);
			} else {
				cout << "null";
			}
			cout << ", ";
			if (t->right) {
				print(t->right, false);
			} else {
				cout << "null";
			}
		}
		cout << ")";
		if (endl) cout << std::endl;
	}
}

void release(TreeNode* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(6);
		t->left = new TreeNode(2);
		t->left->left = new TreeNode(0);
		t->left->right = new TreeNode(4);
		t->left->right->left = new TreeNode(3);
		t->left->right->left = new TreeNode(5);
		t->right = new TreeNode(8);
		t->right->left = new TreeNode(7);
		t->right->right = new TreeNode(9);
		cout << s.lowestCommonAncestor(t, t->left/*2*/, t->right/*8*/)->val << endl; // answer: 6
		cout << s.lowestCommonAncestor(t, t->left/*2*/, t->left->right/*4*/)->val << endl; // answer: 2
		release(t);
	}
	{
		TreeNode* t = new TreeNode(2);
		t->left = new TreeNode(1);
		cout << s.lowestCommonAncestor(t, t/*2*/, t->left/*1*/)->val << endl; // answer: 2
		release(t);
	}
	return 0;
}
