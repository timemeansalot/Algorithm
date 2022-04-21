#include "headfile.h"

class NumArray
{
private:
    int pre_sum[10000];

public:
    NumArray(vector<int> &nums)
    {
        pre_sum[0] = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // pre_sum[0]=0, 表示此时还没有元素
            // pre_sum[1]=nums[0]
            pre_sum[i + 1] = pre_sum[i] + nums[i]; // 计算前缀和，通过前缀和可以在O(1)内算出区间和
        }
        // print]
        // for (int i = 0; i <= nums.size(); i++)
        // {
        //     cout << pre_sum[i] << " ";
        // }
        // cout << endl;
    }

    int sumRange(int left, int right)
    {
        return pre_sum[right + 1] - pre_sum[left];
    }
};
int main()
{
    vector<int> a{-2, 0, 3, -5, 2, -1};

    NumArray n(a);
    int sum = n.sumRange(0,5);
    cout << sum << endl;
    return 0;
}