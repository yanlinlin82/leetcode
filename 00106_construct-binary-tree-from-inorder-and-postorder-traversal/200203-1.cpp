// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = postorder.size();
		if (n == 0) return NULL;
		return buildTree(&inorder[0], &postorder[0], n - 1, n - 1, n);
	}
private:
	TreeNode* buildTree(const int* p, const int* q, int a, int b, int n) {
		if (n < 0) return NULL;
		TreeNode* t = new TreeNode(q[b]);
		int i = 0;
		for (; i < n; ++i) {
			if (p[a - i] == q[b]) break;
		}
		if (i + 1 < n) t->left = buildTree(p, q, a - (i + 1), b - (i + 1), n - (i + 1));
		if (i > 0) t->right = buildTree(p, q, a, b - 1, i);
		return t;
	}
};

int main()
{
	Solution s;
	{
		vector<int> inorder = {9,3,15,20,7};
		vector<int> postorder = {9,15,7,20,3};
		TreeNode* t = s.buildTree(inorder, postorder);
		print(t); // answer: [ 3 9 20 null null 15 7 ]
		release(t);
	}
	return 0;
}
