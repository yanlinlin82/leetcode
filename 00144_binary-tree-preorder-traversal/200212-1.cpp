// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> a;
		visit(root, a);
		return a;
	}
private:
	void visit(TreeNode* t, vector<int>& a) {
		if (t) {
			a.push_back(t->val);
			visit(t->left, a);
			visit(t->right, a);
		}
	}
};

void release(TreeNode* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

void print(const vector<int>& a)
{
	printf("[ "); for (auto e : a) printf("%d ", e); printf("]\n");
}

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(1);
		t->right = new TreeNode(2);
		t->right->left = new TreeNode(3);
		print(s.preorderTraversal(t));
		release(t);
	}
	return 0;
}
