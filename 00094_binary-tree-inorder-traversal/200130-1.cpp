// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
#include <cstdio>
#include <vector>
#include <initializer_list>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create(initializer_list<int> a)
{
	if (a.size() == 0) return NULL;
	auto it = a.begin();
	if (*it <= 0) return NULL;
	TreeNode* t = new TreeNode(*it);
	//printf("create root (%d)\n", t->val);
	vector<TreeNode*> parents{t};
	vector<TreeNode*> children;
	++it;
	for (size_t i = 0; it != a.end();) {
		//printf("add : %d, i = %d\n", *it, i);
		if (i < parents.size() * 2) {
			TreeNode* c = (*it <= 0 ? NULL : new TreeNode(*it));
			TreeNode* n = parents[i / 2];
			if (i % 2 == 0) {
				//if (c) printf("add (%d) to (%d)'s left\n", c->val, n->val);
				n->left = c;
			} else {
				//if (c) printf("add (%d) to (%d)'s right\n", c->val, n->val);
				n->right = c;
			}
			if (c) children.push_back(c);
			++i;
			++it;
		} else {
			parents = children;
			children.clear();
			i = 0;
		}
	}
	return t;
}

void release(TreeNode* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

void print(TreeNode* t, int space = 10)
{
	if (t == NULL) { printf("NULL\n"); return; }
	vector<TreeNode*> parent{t};
	vector<TreeNode*> children;
	for (;;) {
		bool allNull = true;
		for (size_t i = 0; i < parent.size(); ++i) {
			if (parent[i]) { allNull = false; break; }
		}
		if (allNull) break;
		printf("%*s", space, "");
		for (size_t i = 0; i < parent.size(); ++i) {
			if (parent[i]) {
				printf(" %3d ", parent[i]->val);
				children.push_back(parent[i]->left);
				children.push_back(parent[i]->right);
			} else {
				printf(" nul ");
				children.push_back(NULL);
				children.push_back(NULL);
			}
		}
		printf("\n");
		parent = children;
		children.clear();
		space -= 3;
	}
}

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> a;
		visit(root, a);
		return a;
	}
private:
	void visit(TreeNode* t, vector<int>& a) {
		if (t) {
			visit(t->left, a);
			a.push_back(t->val);
			visit(t->right, a);
		}
	}
};

void print(const vector<int>& a)
{
	printf("[ ");
	for (auto e : a) { printf("%d ", e); }
	printf("]\n");
}

int main()
{
	Solution s;
	{
		TreeNode* t = create({1,-1,2,3});
		//print(t);
		print(s.inorderTraversal(t)); // answer: [1,3,2]
	}
	return 0;
}
