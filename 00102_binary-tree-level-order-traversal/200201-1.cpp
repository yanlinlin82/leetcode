// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root) {
			vector<TreeNode*> p{root}, c;
			for (;;) {
				vector<int> a;
				for (size_t i = 0; i < p.size(); ++i) {
					a.push_back(p[i]->val);
					if (p[i]->left) c.push_back(p[i]->left);
					if (p[i]->right) c.push_back(p[i]->right);
				}
				res.push_back(a);
				if (c.empty()) break;
				p = c; c.clear();
			}
		}
		return res;
    }
};

void print(const vector<vector<int>>& a)
{
	printf("[ ");
	for (auto r : a) {
		printf("[ ");
		for (auto e : r) {
			printf("%d ", e);
		}
		printf("] ");
	}
	printf("]\n");
}

int main()
{
	Solution s;
	{
		TreeNode* t = create({3,9,20,NULL,NULL,15,7});
		auto a = s.levelOrder(t);
		print(a); // answer: [ [3], [9,20], [15,7] ]
		release(t);
	}
	return 0;
}
