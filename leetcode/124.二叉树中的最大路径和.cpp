/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include "headfile.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int max_value = -INT32_MAX;
        traverse(root, max_value);
        return max_value;
    }

    int traverse(TreeNode *root, int &max_value)
    {
        if (root == NULL)
            return 0;
        int left = max(0, traverse(root->left, max_value));
        int right = max(0, traverse(root->right, max_value));

        // 后序遍历部分
        int lmr = left + right + root->val;
        max_value = max(lmr, max_value);
        return max(left, right) + root->val;
    }
};
// @lc code=end
