// https://leetcode-cn.com/problems/implement-stack-using-queues/
#include <iostream>
#include <vector>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		s.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int r = 0;
		if (!s.empty()) {
			r = s.back();
			s.pop_back();
		}
		return r;
    }
    
    /** Get the top element. */
    int top() {
		if (s.empty()) return 0;
		return s.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return s.empty();
    }
private:
	vector<int> s;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
	MyStack s;
	s.push(1);
	return 0;
}
