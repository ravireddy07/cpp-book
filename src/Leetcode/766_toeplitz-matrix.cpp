// Problem Statement: https://leetcode.com/problems/toeplitz-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> matrix)
    {
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            int n = matrix[0][i];
            int j = 0;
            int k = i;
            while (j < matrix.size() && k < matrix[0].size())
            {
                if (matrix[j][k] != n)
                    return false;
                j++;
                k++;
            }
        }

        for (int i = 1; i < matrix.size(); ++i)
        {
            int n = matrix[i][0];
            int j = i;
            int k = 0;
            while (j < matrix.size() && k < matrix[0].size())
            {
                if (matrix[j][k] != n)
                    return false;
                j++, k++;
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isToeplitzMatrix({{1, 2}, {2, 2}}) << "\n";
    return 0;
}
