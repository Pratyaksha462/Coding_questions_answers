#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1363227723/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *solve(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return NULL;

        int mid = i + (j - i) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, i, mid - 1);
        root->right = solve(nums, mid + 1, j);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};