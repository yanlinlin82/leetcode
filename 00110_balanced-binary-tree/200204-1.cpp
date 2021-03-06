// https://leetcode-cn.com/problems/balanced-binary-tree/
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
	bool isBalanced(TreeNode* root) {
		int maxDepth = 0;
		return isBalanced(root, maxDepth);
	}
private:
	bool isBalanced(TreeNode* root, int& maxDepth) {
		if (!root) { maxDepth = 0; return true; }
		int maxDepthLeft = 0, maxDepthRight = 0;
		if (!isBalanced(root->left, maxDepthLeft)) return false;
		if (!isBalanced(root->right, maxDepthRight)) return false;
		if (maxDepthLeft < maxDepthRight - 1 || maxDepthLeft > maxDepthRight + 1) return false;
		maxDepth = (maxDepthLeft >= maxDepthRight ? maxDepthLeft : maxDepthRight) + 1;
		return true;
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = create({3,9,20,NULL,NULL,15,7});
		print(t);
		printf("%d\n", s.isBalanced(t)); // answer: true
		release(t);
	}
	{
		TreeNode* t = create({1,2,2,3,3,NULL,NULL,4,4});
		print(t);
		printf("%d\n", s.isBalanced(t)); // answer: false
		release(t);
	}
	return 0;
}
