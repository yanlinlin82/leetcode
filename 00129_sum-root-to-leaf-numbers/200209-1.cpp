// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
#include <cstdio>

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
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		if (root) sumNumbers(root, 0, sum);
		return sum;
	}
private:
	void sumNumbers(TreeNode* t, int prefix, int& sum) {
		int val = prefix * 10 + t->val;
		if (!t->left && !t->right) {
			sum += val;
		} else {
			if (t->left) sumNumbers(t->left, val, sum);
			if (t->right) sumNumbers(t->right, val, sum);
		}
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(1);
		t->left = new TreeNode(2);
		t->right = new TreeNode(3);
		printf("%d\n", s.sumNumbers(t)); // answer: 25
		release(t);
	}
	{
		TreeNode* t = new TreeNode(4);
		t->left = new TreeNode(9);
		t->right = new TreeNode(0);
		t->left->left = new TreeNode(5);
		t->left->right = new TreeNode(1);
		printf("%d\n", s.sumNumbers(t)); // answer: 1026
		release(t);
	}
	return 0;
}
