#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Insert in a Linked List

// Insert at the end

ListNode *Insertatend(int x, ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ListNode *newnode = new ListNode(x);
    temp->next = newnode;

    return head;
}
// Insert at the first
ListNode *insertatstart(int x, ListNode *head)
{

    if (head == nullptr)
    {
        ListNode *newnode = new ListNode(x);
        return newnode;
    }

    ListNode *newnode = new ListNode(x);
    newnode->next = head;
    return newnode;
}
// Insert at the position k
ListNode *insertafterkey(int key, int x, ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->val == key)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;

    ListNode *newnode = new ListNode(x);
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
// Insert before key
ListNode *insertbeforekey(int key, int x, ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->val == key)
    {
        ListNode *newnode = new ListNode(x);
        newnode->next = head;
        return newnode;
    }

    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL && curr->val != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr != nullptr)
    {
        ListNode *newnode = new ListNode(x);
        prev->next = newnode;
        newnode->next = curr;
    }
    return head;
}
// printing the Linkedlist

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {

        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head = insertatstart(2, head);
    head = Insertatend(3, head);
    head = insertafterkey(2, 4, head);

    print(head);
    return 0;
}