#include "headfile.h"
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0;
        int key=0;
        int min=0;
        int length = nums.size();
        vector<int> res;
        // is nums has only 1 or 2 items
        if (length == 1)
        {
            res.push_back(nums[0] * nums[0]);
            return res;
        }
        else if (length == 2)
        {
            if (nums[0] * nums[0] < nums[1] * nums[1])
            {
                res.push_back(nums[0] * nums[0]);
                res.push_back(nums[1] * nums[1]);
            }
            else
            {
                res.push_back(nums[1] * nums[1]);
                res.push_back(nums[0] * nums[0]);
            }
            return res;
        }

        // find the minimun point
        min=nums[i]*nums[i];
        key=0;
        min=0x7fffffff;
        for(i=0;i<length;i++)
        {
            if(nums[i]*nums[i]<min)
            {
                key=i;
                min=nums[i]*nums[i];
            }
        }

        int j = key - 1, k = key + 1;

        res.push_back(nums[key] * nums[key]);
        while (j >= 0 && k < length)
        {
            if (nums[j] * nums[j] < nums[k] * nums[k])
            {
                res.push_back(nums[j] * nums[j]);
                j--;
            }
            else
            {
                res.push_back(nums[k] * nums[k]);
                k++;
            }
        }
        while (j >= 0)
        {
            res.push_back(nums[j] * nums[j]);
            j--;
        }
        while (k < length)
        {
            res.push_back(nums[k] * nums[k]);
            k++;
        }

        return res;
    }
};
int main()
{
    // vector<int> s = {-1,2,2};
    // vector<int> s = {-4, -1, 0, 3, 10};
    vector<int> s = {-10,-5,-5,-4,-3,-3,-3,5,9,10};
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    Solution sol;
    vector<int> res = sol.sortedSquares(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}