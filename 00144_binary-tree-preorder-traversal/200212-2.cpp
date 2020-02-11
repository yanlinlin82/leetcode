// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// 进阶：使用迭代算法（而非递归算法）
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
		vector<TreeNode*> stack;
		TreeNode* p = root;
		for (;;) {
			for (; p; p = p->left) {
				a.push_back(p->val);
				stack.push_back(p);
			}
			if (stack.empty()) break;
			p = stack.back()->right;
			stack.pop_back();
		}
		return a;
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
