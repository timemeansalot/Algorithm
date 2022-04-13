#include "headfile.h"

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
// void InOrder(TreeNode *root, int &k)
// {
//     if (root == nullptr)
//         return;
//     InOrder(root->left, k);
//     k++;
//     cout << root->val << ":" << k << endl;

//     InOrder(root->right, k);
// }
int main()
{
    TreeNode root(3);
    TreeNode r2(1);
    TreeNode r3(3);
    TreeNode r4(4);
    TreeNode r5(2);
    TreeNode r6(6);
    TreeNode r7(7);

    root.left = &r2;
    root.right = &r3;

    r2.left = nullptr;
    r2.right = &r5;

    r3.left = nullptr;
    r3.right = nullptr;

    Solution s;
    cout << s.kthSmallest(&root, 1) << endl;

    // TreeNode *p = (TreeNode *)nullptr;
    return 0;
}