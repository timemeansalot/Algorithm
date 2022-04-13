/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *res = new TreeNode();
        res = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return res;
    }

    TreeNode *build(vector<int> &preorder, int pre_start, int pre_end,
                    vector<int> &inorder, int in_start, int in_end)
    {
        // 先序遍历的部分
        if (pre_start > pre_end)
            return nullptr;
        int root_value = preorder[pre_start];
        TreeNode *root = new TreeNode(root_value);
        if (pre_start > pre_end)
            return nullptr;
        // find root in in_order
        int index = in_start;
        while (index < in_end)
        {
            if (inorder[index] == root_value)
                break;
            index++;
        }
        int left_size = index - in_start;
        // 递归左右子树
        root->left = build(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, index - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, inorder, index + 1, in_end);
        return root;
    }
};
// @lc code=end
