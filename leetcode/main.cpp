#include "headfile.h"
class NumMatrix
{
private:
    int **pre_sum; // 动态数组指针

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        // pre_sum矩阵第0行和第0列都为0，方便计算区间和
        pre_sum = new int *[matrix.size()+1];
        for (int i = 0; i < matrix.size()+1; i++)
        {
            pre_sum[i] = new int[matrix[0].size()+1];
        }

        for (int i = 0; i < matrix.size(); i++)
            pre_sum[i][0] = 0;
        for (int i = 0; i < matrix[0].size(); i++)
            pre_sum[0][i] = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                pre_sum[i + 1][j + 1] = pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j] + matrix[i][j];
            }
        }

        // print pre_sum
        cout << "pre_sum matrix: " << endl;
        for (int i = 0; i <= matrix.size(); i++)
        {
            for (int j = 0; j <= matrix[0].size(); j++)
            {
                cout << pre_sum[i][j] << " ";
            }
            cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row1][col2 + 1] - pre_sum[row2 + 1][col1] + pre_sum[row1][col1];
    }
};

int main()
{

    vector<vector<int>> matrix{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    cout << matrix.size() << " " << matrix[0].size() << endl;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    NumMatrix m(matrix);
    int sum1 = m.sumRegion(2, 1, 4, 3);
    int sum2 = m.sumRegion(1, 1, 2, 2);
    int sum3 = m.sumRegion(1, 2, 2, 4);
    cout << sum1 << endl;
    cout << sum2 << endl;
    cout << sum3 << endl;
    return 0;
}