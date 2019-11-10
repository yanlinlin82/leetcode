// https://leetcode-cn.com/problems/merge-k-sorted-lists/
#include <cstdio>
#include <vector>
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* p = NULL;
		if (!lists.empty()) {
			p = lists.front();
			for (int i = 1; i < lists.size(); ++i) {
				p = mergeTwoLists(p, lists[i]);
			}
		}
		return p;
	}
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* r;
        if (l1->val <= l2->val) {
            r = l1;
            l1 = l1->next;
        } else {
            r = l2;
            l2 = l2->next;
        }
        ListNode* p = r;
        while (l1 || l2) {
            if (l1 == NULL) {
                p->next = l2;
                l2 = l2->next;
            } else if (l2 == NULL) {
                p->next = l1;
                l1 = l1->next;
            } else {
                if (l1->val <= l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            p = p->next;
        }
        return r;
    }
};

void print(ListNode* p)
{
	for (; p; p = p->next) {
		printf("%d ", p->val);
	}
	printf("\n");
}

void print(const vector<ListNode*>& lists)
{
	for (const auto& p : lists) {
		print(p);
	}
}

ListNode* create(initializer_list<int> a)
{
	ListNode* list = NULL;
	ListNode* prev = NULL;
	for (auto it = a.begin(); it != a.end(); ++it) {
		ListNode* p = new ListNode(*it);
		if (prev == NULL) {
			list = p;
			prev = p;
		} else {
			prev->next = p;
			prev = p;
		}
	}
	return list;
}

void destroy(ListNode* p)
{
	while (p) {
		ListNode* next = p->next;
		delete p;
		p = next;
	}
}

int main()
{
	Solution s;
	vector<ListNode*> lists;
	lists.push_back(create({1,4,5}));
	lists.push_back(create({1,3,4}));
	lists.push_back(create({2,6}));
	print(lists);
	ListNode* p = s.mergeKLists(lists);
	print(p);
	destroy(p);
	return 0;
}
