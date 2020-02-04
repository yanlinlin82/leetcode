// https://leetcode-cn.com/problems/path-sum-ii/
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

void print(const vector<vector<int>>& a)
{
	printf("[\n");
	for (const auto& r : a) {
		printf("  [ ");
		for (auto e : r) {
			printf("%d ", e);
		}
		printf("]\n");
	}
	printf("]\n");
}

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (root) pathSum(res, root, sum, vector<int>());
		return res;
	}
private:
	void pathSum(vector<vector<int>>& res, TreeNode* t, int sum, vector<int> a) {
		if (!t->left && !t->right) {
			if (t->val == sum) {
				a.push_back(t->val);
				res.push_back(a);
			}
		} else {
			a.push_back(t->val);
			if (t->left) pathSum(res, t->left, sum - t->val, a);
			if (t->right) pathSum(res, t->right, sum - t->val, a);
		}
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = create({5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1});
		print(s.pathSum(t, 22)); // answer: [ [5,4,11,2], [5,8,4,5] ]
		release(t);
	}
	return 0;
}
