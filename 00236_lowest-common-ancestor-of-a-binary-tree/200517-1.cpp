// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		unordered_map<TreeNode*, TreeNode*> parent_of;
		visit(parent_of, root);
		unordered_set<TreeNode*> a;
		for (TreeNode* t = p; t; t = parent_of[t]) {
			a.insert(t);
		}
		for (TreeNode* t = q; t; t = parent_of[t]) {
			if (a.find(t) != a.end()) {
				return t;
			}
		}
		return root;
	}
private:
	void visit(unordered_map<TreeNode*, TreeNode*>& parent_of, TreeNode* t) {
		if (t) {
			if (t->left) parent_of[t->left] = t;
			if (t->right) parent_of[t->right] = t;
			visit(parent_of, t->left);
			visit(parent_of, t->right);
		}
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
		t->left = new TreeNode(5);
		t->left->left = new TreeNode(6);
		t->left->right = new TreeNode(2);
		t->left->right->left = new TreeNode(7);
		t->left->right->right = new TreeNode(4);
		t->right = new TreeNode(1);
		t->right->left = new TreeNode(0);
		t->right->right = new TreeNode(8);
		print(t);
		cout << s.lowestCommonAncestor(t, t->left/*5*/, t->right/*1*/)->val << endl; // answer: 3
		cout << s.lowestCommonAncestor(t, t->left/*5*/, t->left->right->right/*4*/)->val << endl; // answer: 5
		release(t);
	}
	return 0;
}
