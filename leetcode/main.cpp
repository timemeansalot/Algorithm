#include "headfile.h"
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

int main()
{
    vector<int> preorder{1, 2};
    vector<int> inorder{2, 1};
    Solution s;
    TreeNode *res = new TreeNode;
    cout << res->val << endl;
    res = s.buildTree(preorder, inorder);

    // TreeNode *p = (TreeNode *)nullptr;
    return 0;
}