// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
#include <cstdio>
#include <algorithm>
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
	int maxPathSum(TreeNode* root) {
		if (!root->left && !root->right) return root->val;
		int a = maxRootPathSum(root->left);
		int b = maxRootPathSum(root->right);
		int s = a + root->val + b;
		if (s < root->val + a) { s = root->val + a; }
		if (s < root->val + b) { s = root->val + b; }
		if (s < root->val) { s = root->val; }
		if (root->left && s < a) { s = a; }
		if (root->right && s < b) { s = b; }
		if (root->left) {
			a = maxPathSum(root->left);
			if (s < a) { s = a; }
		}
		if (root->right) {
			b = maxPathSum(root->right);
			if (s < b) { s = b; }
		}
		return s;
	}
private:
	int maxRootPathSum(TreeNode* t) { // path that starts with root node
		if (!t) return 0;
		int a = maxRootPathSum(t->left);
		int b = maxRootPathSum(t->right);
		return t->val + max(0, max(a, b));
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(1);
		t->left = new TreeNode(2);
		t->right = new TreeNode(3);
		printf("%d\n", s.maxPathSum(t)); // answer: 6
		release(t);
	}
	{
		TreeNode* t = new TreeNode(-10);
		t->left = new TreeNode(9);
		t->right = new TreeNode(20);
		t->right->left = new TreeNode(15);
		t->right->right = new TreeNode(7);
		printf("%d\n", s.maxPathSum(t)); // answer: 42
		release(t);
	}
	{
		TreeNode* t = new TreeNode(-3);
		printf("%d\n", s.maxPathSum(t)); // answer: -3
		release(t);
	}
	{
		TreeNode* t = new TreeNode(-2);
		t->right = new TreeNode(-1);
		printf("%d\n", s.maxPathSum(t)); // answer: -1
		release(t);
	}
	{
		TreeNode* t = new TreeNode(9);
		t->left = new TreeNode(6);
		t->right = new TreeNode(-3);
		t->right->left = new TreeNode(-6);
		t->right->right = new TreeNode(2);
		t->right->right->left = new TreeNode(2);
		t->right->right->left->left = new TreeNode(-6);
		t->right->right->left->right = new TreeNode(-6);
		t->right->right->left->left->left = new TreeNode(-6);
		/*      9
		 *     / \
		 *    6  -3
		 *       / \
		 *     -6   2
		 *         /
		 *        2
		 *       / \
		 *     -6   -6
		 *     /
		 *   -6
		 */
		printf("%d\n", s.maxPathSum(t)); // answer: 16
		release(t);
	}
	return 0;
}
