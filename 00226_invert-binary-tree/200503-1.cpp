// https://leetcode-cn.com/problems/invert-binary-tree/
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
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
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
		TreeNode* t = new TreeNode(4);
		t->left = new TreeNode(2);
		t->left->left = new TreeNode(1);
		t->left->right = new TreeNode(3);
		t->right = new TreeNode(7);
		t->right->left = new TreeNode(6);
		t->right->right = new TreeNode(9);
		print(t);
		s.invertTree(t);
		print(t);
		release(t);
	}
	return 0;
}
