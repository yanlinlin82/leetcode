// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> a;
		if (root) {
			vector<pair<TreeNode*,int>> stack;
			stack.push_back(make_pair(root,0));
			while (!stack.empty()) {
				auto& b = stack.back();
				if (b.second == 0) {
					b.second = 1;
					if (b.first->left) {
						stack.push_back(make_pair(b.first->left, 0));
					}
				} else if (b.second == 1) {
					b.second = 2;
					if (b.first->right) {
						stack.push_back(make_pair(b.first->right, 0));
					}
				} else {
					a.push_back(b.first->val);
					stack.pop_back();
				}
			}
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
		print(s.postorderTraversal(t));
		release(t);
	}
	return 0;
}
