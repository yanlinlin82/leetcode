// https://leetcode-cn.com/problems/min-stack/
#include <cstdio>
#include <vector>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack(): stack(1) {
	}

	void push(int x) {
		//printf("push(%d)\n", x);
		int index = stack.size();
		stack.push_back(Node(x));
		int i = stack.front().next;
		for (; i != 0; i = stack[i].next) {
			if (stack[i].val > x) break;
		}
		stack[index].prev = stack[i].prev;
		stack[index].next = i;
		stack[stack[i].prev].next = index;
		stack[i].prev = index;
		//dump();
	}

	void pop() {
		//printf("pop\n");
		int index = stack.size() - 1;
		stack[stack[index].prev].next = stack[index].next;
		stack[stack[index].next].prev = stack[index].prev;
		stack.pop_back();
		//dump();
	}

	int top() {
		return stack.back().val;
	}

	int getMin() {
		int index = stack.front().next;
		return stack[index].val;
	}
private:
	void dump() {
		printf("[ ");
		for (int i = 0; i < stack.size(); ++i) {
			printf("(%d,%d,%d) ", stack[i].val, stack[i].prev, stack[i].next);
		}
		printf("]\n");
	}

	struct Node {
		int val, prev, next;
		Node(int v = 0): val(v), prev(0), next(0) { }
	};
	vector<Node> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();  // --> 返回 -3.
	minStack.pop();
	minStack.top();     // --> 返回 0.
	minStack.getMin();  // --> 返回 -2.
	return 0;
}
