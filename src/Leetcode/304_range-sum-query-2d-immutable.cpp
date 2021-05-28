// Problem Statement: https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>> matrix)
    {
        sums = matrix;
        if (matrix.size() == 0)
            return;
        for (int i = 1; i < matrix[0].size(); ++i)
            sums[0][i] += sums[0][i - 1];
        for (int i = 1; i < matrix.size(); ++i)
            sums[i][0] += sums[i - 1][0];
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 1; j < matrix[0].size(); ++j)
                sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = sums[row2][col2];
        if (col1 > 0)
            ans -= sums[row2][col1 - 1];
        if (row1 > 0)
            ans -= sums[row1 - 1][col2];
        if (row1 > 0 && col1 > 0)
            ans += sums[row1 - 1][col1 - 1];
        return ans;
    }

    /***** Another Solution *****/
    vector<vector<int>> temp;
    NumMatrix(vector<vector<int>> matrix)
    {
        temp = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
            for (int j = col1; j <= col2; ++j)
                sum += temp[i][j];
        return sum;
    }
};

int main()
{
    NumMatrix *obj = new NumMatrix({{3, 0, 1, 4, 2},
                                    {5, 6, 3, 2, 1},
                                    {1, 2, 0, 1, 5},
                                    {4, 1, 0, 1, 7},
                                    {1, 0, 3, 0, 5}});
    cout << obj->sumRegion(2, 1, 4, 3) << "\n";
    return 0;
}
