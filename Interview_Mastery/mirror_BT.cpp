#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool solve(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL || r == NULL)
            return false;
        if (l->val == r->val)
            return solve(l->left, r->right) && solve(l->right, r->left);

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL || root->right == NULL)
            return false;
        return solve(root->left, root->right);
    }
};