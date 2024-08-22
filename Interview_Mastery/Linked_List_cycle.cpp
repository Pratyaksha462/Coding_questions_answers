#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/linked-list-cycle/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *t1 = head;
        ListNode *t2 = head;
        if (head == NULL)
            return false;

        while (t2->next != NULL && t2->next->next != NULL)
        {

            t1 = t1->next;
            t2 = t2->next->next;
            if (t1 == t2)
                return true;
        }
        return false;
    }
};