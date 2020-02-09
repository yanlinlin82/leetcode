// https://leetcode-cn.com/problems/clone-graph/
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

void visit(Node* t, vector<Node*>& n)
{
	if (t) {
		if (n.size() < t->val) {
			n.resize(t->val);
		}
		if (!n[t->val - 1]) {
			n[t->val - 1] = t;
			for (auto e : t->neighbors) {
				visit(e, n);
			}
		}
	}
}

void print(Node* t)
{
	vector<Node*> n; visit(t, n);
	printf("[");
	for (auto e : n) {
		printf("[");
		if (e) {
			for (int i = 0; i < e->neighbors.size(); ++i) {
				printf("%s%d", (i>0?",":""), e->neighbors[i]->val);
			}
		}
		printf("]");
	}
	printf("]\n");
}

void release(Node* t)
{
	vector<Node*> n; visit(t, n);
	for (auto e : n) delete(e);
}

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return NULL;
		unordered_map<Node*, Node*> m;
		visit(node, m);
		for (auto [a, b] : m) {
			for (auto e : a->neighbors) {
				b->neighbors.push_back(m[e]);
			}
		}
		return m[node];
	}
private:
	void visit(Node* t, unordered_map<Node*, Node*>& m) {
		if (m.find(t) == m.end()) {
			m[t] = new Node(t->val);
			for (auto n : t->neighbors) {
				visit(n, m);
			}
		}
	}
};

int main()
{
	Solution s;
	{
		Node* t1 = new Node(1);
		Node* t2 = new Node(2);
		Node* t3 = new Node(3);
		Node* t4 = new Node(4);
		t1->neighbors.push_back(t2);
		t1->neighbors.push_back(t4);
		t2->neighbors.push_back(t1);
		t2->neighbors.push_back(t3);
		t3->neighbors.push_back(t2);
		t3->neighbors.push_back(t4);
		t4->neighbors.push_back(t1);
		t4->neighbors.push_back(t3);
		print(t1);
		Node* c = s.cloneGraph(t1);
		print(c);
		release(c);
		release(t1);
	}
	{
		Node* t1 = new Node(1);
		print(t1);
		Node* c = s.cloneGraph(t1);
		print(c);
		release(c);
		release(t1);
	}
	{
		Node* t1 = NULL;
		print(t1);
		Node* c = s.cloneGraph(t1);
		print(c);
		release(c);
		release(t1);
	}
	{
		Node* t1 = new Node(1);
		Node* t2 = new Node(2);
		t1->neighbors.push_back(t2);
		t2->neighbors.push_back(t1);
		print(t1);
		Node* c = s.cloneGraph(t1);
		print(c);
		release(c);
		release(t1);
	}
	return 0;
}
