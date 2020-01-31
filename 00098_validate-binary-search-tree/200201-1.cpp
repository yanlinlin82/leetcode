// https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
		if (!root) return true;
		int min, max;
		return isValidBST(root, min, max);
	}
private:
	bool isValidBST(TreeNode* t, int& min, int& max) {
		min = max = t->val;
		if (t->left) {
			int a, b;
			if (!isValidBST(t->left, a, b)) return false;
			if (b >= t->val) return false;
			min = a;
		}
		if (t->right) {
			int a, b;
			if (!isValidBST(t->right, a, b)) return false;
			if (a <= t->val) return false;
			max = b;
		}
		return true;
	}
};

int main()
{
	Solution s;
	{
		TreeNode* t = create({2,1,3});
		//print(t);
		printf("%d\n", s.isValidBST(t)); // answer: true
		release(t);
	}
	{
		TreeNode* t = create({5,1,4,0,0,3,6});
		//print(t);
		printf("%d\n", s.isValidBST(t)); // answer: false
		release(t);
	}
	{
		TreeNode* t = create({1,1});
		//print(t);
		printf("%d\n", s.isValidBST(t)); // answer: false
		release(t);
	}
	{
		TreeNode* t = create({10,5,15,0,0,6,20});
		//print(t);
		printf("%d\n", s.isValidBST(t)); // answer: false
		release(t);
	}
	return 0;
}
