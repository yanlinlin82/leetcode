// https://leetcode-cn.com/problems/merge-two-sorted-lists/
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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

void print(const char* prefix, ListNode* l)
{
    printf("%s", prefix);
    while (l) {
        printf(" %d", l->val);
        l = l->next;
    }
    printf("\n");
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    print("l1 =", l1);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    print("l2 =", l2);
    Solution s;
    ListNode* l = s.mergeTwoLists(l1, l2);
    print("l =", l);
    return 0;
}