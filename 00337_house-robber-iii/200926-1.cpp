// https://leetcode-cn.com/problems/house-robber-iii/
// 挑战失败：超出时间限制
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
	int rob(TreeNode* root) {
		return rob(root, true);
	}
private:
	int rob(TreeNode* root, bool allowRobRoot) {
		if (!root) return 0;
		int a = rob(root->left, true) + rob(root->right, true);
		if (allowRobRoot) {
			int b = rob(root->left, false) + root->val + rob(root->right, false);
			if (b > a) {
				a = b;
			}
		}
		return a;
	}
};

void release(TreeNode* t) {
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
		TreeNode* t = new TreeNode(3);
		t->left = new TreeNode(2);
		t->left->right = new TreeNode(3);
		t->right = new TreeNode(3);
		t->right->right = new TreeNode(1);
		cout << s.rob(t) << endl; // answer: 7
		release(t);
	}
	{
		TreeNode* t = new TreeNode(3);
		t->left = new TreeNode(4);
		t->left->left = new TreeNode(1);
		t->left->right = new TreeNode(3);
		t->right = new TreeNode(5);
		t->right->right = new TreeNode(1);
		cout << s.rob(t) << endl; // answer: 9
		release(t);
	}
	return 0;
}
