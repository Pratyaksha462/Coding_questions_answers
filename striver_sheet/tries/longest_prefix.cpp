#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *children[26];
    bool eow;

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        eow = false;
    }
};

void insert(Node *root, const string &s)
{
    Node *curr = root;
    for (char c : s)
    {
        int idx = c - 'a';
        if (curr->children[idx] == nullptr)
        {
            curr->children[idx] = new Node();
        }
        curr = curr->children[idx];
    }
    curr->eow = true;
}
string longestStringWithAllPrefix(Node *root, const string &pre)
{
    if (root == nullptr)
    {
        return pre;
    }
    string longest = pre;
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != nullptr && root->children[i]->eow)
        {
            string s = pre + (char)(i + 'a');
            string curr = longestStringWithAllPrefix(root->children[i], s);
            if (curr.length() > longest.length())
            {
                longest = curr;
            }
        }
    }
    return longest;
}
string completeString(int n, vector<string> &a)
{
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        insert(root, s);
    }
    string ans = longestStringWithAllPrefix(root, "");
    if (ans.length() == 0)
        return "None";
    else
        return ans;

    //    return longestStringWithAllPrefix(root,"");
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
    }
    return 0;
}