#include "headfile.h"
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

int main()
{
    TreeNode *t1=new TreeNode;
    TreeNode *t2=new TreeNode;
    TreeNode *t3=new TreeNode;

    t1->val = 1;
    t2->val = 2;
    t3->val = 3;

    t1->left = t2;
    t1->right = t3;

    Solution s;
    int ans = s.maxPathSum(t1);
    cout << ans << endl;
}