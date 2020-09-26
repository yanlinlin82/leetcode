// https://leetcode-cn.com/problems/house-robber-iii/
#include <iostream>
#include <unordered_map>
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
		unordered_map<TreeNode*, unordered_map<bool, int>> m;
		return rob(root, true, m);
	}
private:
	int rob(TreeNode* root, bool allowRobRoot,
			unordered_map<TreeNode*, unordered_map<bool, int>>& m) {
		if (!root) return 0;
		auto it = m.find(root);
		if (it != m.end()) {
			auto it2 = it->second.find(allowRobRoot);
			if (it2 != it->second.end()) {
				return it2->second;
			}
		}
		int a = rob(root->left, true, m) + rob(root->right, true, m);
		m[root][false] = a;
		if (allowRobRoot) {
			int b = rob(root->left, false, m) + root->val + rob(root->right, false, m);
			if (b > a) {
				a = b;
			}
			m[root][true] = a;
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
