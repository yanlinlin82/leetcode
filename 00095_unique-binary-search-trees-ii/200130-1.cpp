// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
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

void draw(TreeNode* t, int space = 10)
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

void visit(TreeNode* t)
{
	if (!t) {
		printf(" null");
	} else {
		printf(" %d", t->val);
		visit(t->left);
		visit(t->right);
	}
}

void print(TreeNode* t)
{
	printf("[");
	visit(t);
	printf(" ]\n");
}

void print(vector<TreeNode*>& a)
{
	printf("[\n");
	for (auto t : a) {
		printf("  ");
		print(t);
	}
	printf("]\n");
}

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		generateTrees(res, 1, n);
		return res;
	}
private:
	void generateTrees(vector<TreeNode*>& res, int start, int end) {
		if (start == end) {
			TreeNode* t = new TreeNode(start);
			res.push_back(t);
		} else if (start + 1 == end) {
			TreeNode* t1 = new TreeNode(start);
			TreeNode* t2 = new TreeNode(end);
			t1->right = t2;
			res.push_back(t1);
			TreeNode* t3 = new TreeNode(start);
			TreeNode* t4 = new TreeNode(end);
			t4->left = t3;
			res.push_back(t4);
		} else {
			for (int i = start; i <= end; ++i) {
				TreeNode root(i);
				vector<TreeNode*> a;
				if (i == start) {
					TreeNode* n = clone(&root);
					a.push_back(n);
				} else {
					vector<TreeNode*> b;
					generateTrees(b, start, i - 1);
					for (int j = 0; j < b.size(); ++j) {
						TreeNode* n = clone(&root);
						n->left = b[j];
						a.push_back(n);
					}
				}
				if (i == end) {
					for (int i = 0; i < a.size(); ++i) {
						res.push_back(a[i]);
					}
				} else {
					vector<TreeNode*> b;
					generateTrees(b, i + 1, end);
					for (int j = 0; j < a.size(); ++j) {
						for (int k = 0; k < b.size(); ++k) {
							TreeNode* n = clone(a[j]);
							n->right = clone(b[k]);
							res.push_back(n);
						}
					}
					for (int j = 0; j < a.size(); ++j) {
						release(a[j]);
					}
					for (int k = 0; k < b.size(); ++k) {
						release(b[k]);
					}
				}
			}
		}
	}
	TreeNode* clone(TreeNode* t) {
		if (!t) return NULL;
		TreeNode* n = new TreeNode(t->val);
		n->left = clone(t->left);
		n->right = clone(t->right);
		return n;
	}
	void release(TreeNode* t)
	{
		if (t) {
			release(t->left);
			release(t->right);
			delete t;
		}
	}
};

int main()
{
	Solution s;
	{
		vector<TreeNode*> a = s.generateTrees(3);
		print(a);
	}
	return 0;
}
