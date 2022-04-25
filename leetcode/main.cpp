#include "headfile.h"

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int left = 0, right = nums1.size() - 1;
        priority_queue<pair<int, int>> pq;
        vector<int> res(nums1.size());

        for (int i = 0; i < nums2.size(); i++)
            pq.push(make_pair(nums2[i], i));

        sort(nums1.begin(), nums1.end(), greater<int>());

        while (left <= right)
        {
            if (nums1[left] > pq.top().first)
            {
                res[pq.top().second] = nums1[left];
                left++;
                pq.pop();
            }
            else
            {
                res[pq.top().second] = nums1[right];
                right--;
                pq.pop();
            }
        }
        return res;
    }
};
void show_vector(vector<int> &nums)
{
    cout << "vector items: ";
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
}
int main()
{
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {1, 10, 4, 11};
    Solution s;
    vector<int> res = s.advantageCount(nums1, nums2);
    show_vector(res);

    return 0;
}