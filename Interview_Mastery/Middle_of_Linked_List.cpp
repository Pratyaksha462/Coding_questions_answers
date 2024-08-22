// https://leetcode.com/problems/middle-of-the-linked-list/submissions/1363233070/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;
        int k = 0;
        while (temp != NULL)
        {
            k++;
            temp = temp->next;
        }
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};