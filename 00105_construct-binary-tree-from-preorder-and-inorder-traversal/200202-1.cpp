// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <cstdio>
#include <vector>
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
	vector<TreeNode*> parents{t};
	vector<TreeNode*> children;
	++it;
	for (size_t i = 0; it != a.end();) {
		if (i < parents.size() * 2) {
			TreeNode* c = (*it <= 0 ? NULL : new TreeNode(*it));
			TreeNode* n = parents[i / 2];
			if (i % 2 == 0) { n->left = c; } else { n->right = c; }
			if (c) children.push_back(c);
			++i; ++it;
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

void print(TreeNode* t)
{
	vector<TreeNode*> a{t};
	int last = 0;
	for (int i = 0;;) {
		int end = a.size();
		for (; i < end; ++i) {
			a.push_back(a[i] ? a[i]->left : NULL);
			a.push_back(a[i] ? a[i]->right : NULL);
			if (a[i]) {
				if (a[i]->right) last = a.size() - 1;
				else if (a[i]->left) last = a.size() - 2;
			}
		}
		if (last < end) break;
	}
	a.resize(last + 1);
	printf("[ ");
	for (auto e : a) {
		if (e) {
			printf("%d ", e->val);
		} else {
			printf("null ");
		}
	}
	printf("]\n");
}

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		if (n == 0) return NULL;
		return buildTree(&preorder[0], &inorder[0], n);
	}
private:
	TreeNode* buildTree(const int* p, const int* q, int n) {
		if (n < 0) return NULL;
		TreeNode* t = new TreeNode(*p);
		int i = 0;
		for (; i < n; ++i) {
			if (q[i] == *p) break;
		}
		if (i > 0) t->left = buildTree(p + 1, q, i);
		if (i + 1 < n) t->right = buildTree(p + i + 1, q + i + 1, n - i - 1);
		return t;
	}
};

int main()
{
	Solution s;
	{
		vector<int> preorder = {3,9,20,15,7};
		vector<int> inorder = {9,3,15,20,7};
		TreeNode* t = s.buildTree(preorder, inorder);
		print(t); // answer: [ 3 9 20 null null 15 7 ]
		release(t);
	}
	{
		vector<int> preorder = {1,2,3};
		vector<int> inorder = {3,2,1};
		TreeNode* t = s.buildTree(preorder, inorder);
		print(t); // answer: [ 1 2 null 3 ]
		release(t);
	}
	{
		vector<int> preorder = {1,2,3};
		vector<int> inorder = {2,3,1};
		TreeNode* t = s.buildTree(preorder, inorder);
		print(t); // answer: [ 1 2 null null 3 ]
		release(t);
	}
	return 0;
}
