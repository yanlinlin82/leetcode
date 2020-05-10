// https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		a.push_back(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (b.empty()) {
			while (!a.empty()) {
				int x = a.back();
				a.pop_back();
				b.push_back(x);
			}
		}
		int x = b.back();
		b.pop_back();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (b.empty()) {
			while (!a.empty()) {
				int x = a.back();
				a.pop_back();
				b.push_back(x);
			}
		}
		return b.back();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return a.empty() && b.empty();
	}
private:
	vector<int> a, b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main()
{
	MyQueue q;
	q.push(4);
	int p2 = q.pop(); cout << p2 << endl;
	int p3 = q.peek(); cout << p3 << endl;
	bool p4 = q.empty(); cout << p4 << endl;
	return 0;
}
