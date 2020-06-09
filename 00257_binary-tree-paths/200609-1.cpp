// https://leetcode-cn.com/problems/binary-tree-paths/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> a;
		visit(root, a, "");
		return a;
	}
private:
	void visit(TreeNode* t, vector<string>& a, string prefix) {
		if (t) {
			prefix += (prefix.empty() ? "" : "->") + to_string(t->val);
			if (!t->left && !t->right) {
				a.push_back(prefix);
			} else {
				if (t->left) {
					visit(t->left, a, prefix);
				}
				if (t->right) {
					visit(t->right, a, prefix);
				}
			}
		}
	}
};

void print(TreeNode* t, bool endl = true)
{
	if (t) {
		cout << "(" << t->val;
		if (t->left || t->right) {
			cout << ", ";
			if (t->left) {
				print(t->left, false);
			} else {
				cout << "null";
			}
			cout << ", ";
			if (t->right) {
				print(t->right, false);
			} else {
				cout << "null";
			}
		}
		cout << ")";
		if (endl) cout << std::endl;
	}
}

void release(TreeNode* t)
{
	if (t) {
		release(t->left);
		release(t->right);
		delete t;
	}
}

void print(const vector<string>& a)
{
	cout << "[ ";
	for (const auto& s : a) {
		cout << "\"" << s << "\" ";
	}
	cout << "]" << endl;
}

int main()
{
	Solution s;
	{
		TreeNode* t = new TreeNode(1);
		t->left = new TreeNode(2);
		t->right = new TreeNode(3);
		t->left->right = new TreeNode(5);
		print(s.binaryTreePaths(t));
		print(t);
		release(t);
	}
	return 0;
}
