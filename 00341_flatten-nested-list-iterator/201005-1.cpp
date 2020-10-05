// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class NestedInteger {
public:
	NestedInteger(int a = 0): isInt(true), val(a) {
	}
	explicit NestedInteger(const initializer_list<int>& a): isInt(false) {
		for (auto e : a) lst.push_back(NestedInteger(e));
	}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const { return isInt; }

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const { return val; }

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const { return lst; }

public:
	bool isInt{false};
	int val{0};
	vector<NestedInteger> lst;
};

void print(const NestedInteger& a, bool printEndl = true)
{
	if (a.isInteger()) {
		cout << a.getInteger();
	} else {
		cout << "[ ";
		for (auto e : a.getList()) {
			print(e, false);
			cout << " ";
		}
		cout << "]";
	}
	if (printEndl) cout << endl;
}

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList): pos(0) {
		Visit(nestedList);
	}

	int next() {
		return values[pos++];
	}

	bool hasNext() {
		return (pos < values.size());
	}

private:
	void Visit(const vector<NestedInteger>& nestedList) {
		for (auto e : nestedList) {
			if (e.isInteger()) {
				values.push_back(e.getInteger());
			} else {
				Visit(e.getList());
			}
		}
	}
private:
	vector<int> values;
	size_t pos;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
	{
		NestedInteger a{0, 2, 0};
		a.lst[0] = NestedInteger{1, 1};
		a.lst[2] = NestedInteger{1, 1};
		print(a);

		NestedIterator i(a.lst);
		while (i.hasNext()) cout << i.next() << " ";
		cout << endl;
	}
	{
		NestedInteger a{1, 0};
		a.lst[1] = NestedInteger{4, 0};
		a.lst[1].lst[1] = NestedInteger{6};
		print(a);

		NestedIterator i(a.lst);
		while (i.hasNext()) cout << i.next() << " ";
		cout << endl;
	}
	return 0;
}
