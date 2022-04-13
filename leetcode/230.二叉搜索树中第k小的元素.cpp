/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode *root, int k)
    {
        // 根据中序遍历找第k小的节点
        vector<int> v;
        InOrder(root, v);
        return v[k - 1];
    }

    void InOrder(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        InOrder(root->left, v);
        v.push_back(root->val);
        InOrder(root->right, v);
    }
};
// @lc code=end
