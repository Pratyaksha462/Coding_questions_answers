// https://leetcode.com/problems/invert-binary-tree/description/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        else
        {
            TreeNode *temp;
            invertTree(root->left);
            invertTree(root->right);

            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
};