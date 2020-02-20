// https://leetcode-cn.com/problems/binary-search-tree-iterator/
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void release(TreeNode* t) {
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

class BSTIterator {
public:
	BSTIterator(TreeNode* root): curr(-1) {
		list.clear();
		visit(root);
	}

	/** @return the next smallest number */
	int next() {
		if (hasNext()) ++curr;
		if (curr >= list.size()) throw out_of_range("BSTIterator");
		return list[curr]->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (curr + 1 < list.size());
	}
private:
	void visit(TreeNode* t) {
		if (t) {
			visit(t->left);
			list.push_back(t);
			visit(t->right);
		}
	}
	vector<TreeNode*> list;
	int curr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main()
{
	TreeNode* root = new TreeNode(7);
	root->left = new TreeNode(3);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(20);

	BSTIterator iterator(root);
	cout << iterator.next() << endl;                         // 返回 3
	cout << iterator.next() << endl;                         // 返回 7
	cout << (iterator.hasNext() ? "true" : "false") << endl; // 返回 true
	cout << iterator.next() << endl;                         // 返回 9
	cout << (iterator.hasNext() ? "true" : "false") << endl; // 返回 true
	cout << iterator.next() << endl;                         // 返回 15
	cout << (iterator.hasNext() ? "true" : "false") << endl; // 返回 true
	cout << iterator.next() << endl;                         // 返回 20
	cout << (iterator.hasNext() ? "true" : "false") << endl; // 返回 false

	release(root);
	return 0;
}
