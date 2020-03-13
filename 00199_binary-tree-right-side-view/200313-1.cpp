// https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include <iostream>
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> a;
		if (root) {
			vector<TreeNode*> x = {root};
			while (!x.empty()) {
				a.push_back(x.back()->val);
				vector<TreeNode*> x2;
				for (auto& e : x) {
					if (e->left) x2.push_back(e->left);
					if (e->right) x2.push_back(e->right);
				}
				x = x2;
			}
		}
		return a;
	}
};

void print(vector<int>&& a)
{
	cout << "[ "; for (auto& e : a) cout << e << " "; cout << "]" << endl;
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
		TreeNode* t = new TreeNode(1);
		t->left = new TreeNode(2);
		t->right = new TreeNode(3);
		t->left->right = new TreeNode(5);
		t->right->right = new TreeNode(4);
		print(s.rightSideView(t)); // answer: [1,3,4]
		release(t);
	}
	return 0;
}
