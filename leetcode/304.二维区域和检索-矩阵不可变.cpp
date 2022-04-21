/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include "headfile.h"
// @lc code=start
class NumMatrix
{
private:
    int pre_sum[201][201];

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        // pre_sum矩阵第0行和第0列都为0，方便计算区间和
        for (int i = 0; i < 201; i++)
        {
            pre_sum[0][i] = 0;
            pre_sum[i][0] = 0;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                pre_sum[i + 1][j + 1] = pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row1][col2 + 1] - pre_sum[row2 + 1][col1] + pre_sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
