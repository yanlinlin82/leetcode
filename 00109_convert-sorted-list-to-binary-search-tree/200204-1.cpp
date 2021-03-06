// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(initializer_list<int> a) {
	ListNode node(0);
	ListNode* p = &node;
	for (auto e : a) {
		p->next = new ListNode(e);
		p = p->next;
	}
	return node.next;
}

void release(ListNode* p) {
	if (p) release(p->next);
	delete p;
}

void print(ListNode* p, bool hasEndl = true) {
	if (p) {
		printf("%d ", p->val);
		if (p->next) print(p->next, false);
	}
	if (hasEndl) printf("\n");
}

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int n = 0;
		for (ListNode* p = head; p; p = p->next) ++n;
		if (n <= 0) return NULL;
		return sortedListToBST(head, n);
	}
private:
	TreeNode* sortedListToBST(ListNode* p, int n) {
		if (n <= 0) return NULL;
		ListNode* q = p;
		int i = 0;
		for (; i < n / 2; ++i) q = q->next;
		TreeNode* t = new TreeNode(q->val);
		if (q != p) t->left = sortedListToBST(p, i);
		if (q->next) t->right = sortedListToBST(q->next, n - i - 1);
		return t;
	}
};

int main()
{
	Solution s;
	{
		ListNode* n = init({-10, -3, 0, 5, 9});
		TreeNode* t = s.sortedListToBST(n);
		print(t);
		release(t);
	}
	return 0;
}
