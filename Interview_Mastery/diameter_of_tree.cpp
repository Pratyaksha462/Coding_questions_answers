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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int solve(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;

        int l = solve(root->left, diameter);
        int r = solve(root->right, diameter);
        diameter = max(l + r, diameter);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Write Your Code Here.
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};