// https://leetcode-cn.com/problems/count-complete-tree-nodes/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void release(TreeNode* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(1);
		t->left = new TreeNode(2);
		t->right = new TreeNode(3);
		t->left->left = new TreeNode(4);
		t->left->right = new TreeNode(5);
		t->right->left = new TreeNode(6);
		cout << s.countNodes(t) << endl; // answer: 3
		release(t);
	}
	return 0;
}
