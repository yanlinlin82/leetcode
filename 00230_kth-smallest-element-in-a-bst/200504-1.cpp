// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
	int kthSmallest(TreeNode* root, int k) {
		int n = getTreeNodeCount(root->left);
		if (n == k - 1) {
			return root->val;
		} else if (n > k - 1) {
			return kthSmallest(root->left, k);
		} else {
			return kthSmallest(root->right, k - n - 1);
		}
	}
private:
	int getTreeNodeCount(TreeNode* t) {
		if (!t) return 0;
		return 1 + getTreeNodeCount(t->left) + getTreeNodeCount(t->right);
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
		TreeNode* t = new TreeNode(3);
		t->left = new TreeNode(1);
		t->right = new TreeNode(4);
		t->left->right = new TreeNode(2);
		print(t);
		cout << s.kthSmallest(t, 1) << endl; // answer: 1
		release(t);
	}
	{
		TreeNode* t = new TreeNode(5);
		t->left = new TreeNode(3);
		t->right = new TreeNode(6);
		t->left->left = new TreeNode(2);
		t->left->right = new TreeNode(4);
		t->left->left->left = new TreeNode(1);
		print(t);
		cout << s.kthSmallest(t, 3) << endl; // answer: 3
		release(t);
	}
	{
		TreeNode* t = new TreeNode(1);
		t->right = new TreeNode(2);
		print(t);
		cout << s.kthSmallest(t, 2) << endl; // answer: 2
		release(t);
	}
	return 0;
}
