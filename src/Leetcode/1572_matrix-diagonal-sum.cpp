// Problem Statement: https://leetcode.com/problems/matrix-diagonal-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> mat)
    {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            sum += mat[i][i];
            sum += mat[i][mat.size() - 1 - i];
        }

        if (mat.size() % 2 != 0)
            sum -= mat[mat.size() / 2][mat.size() / 2];
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.diagonalSum({{1, 1, 1, 1},
                           {1, 1, 1, 1},
                           {1, 1, 1, 1},
                           {1, 1, 1, 1}})
         << "\n";
    return 0;
}
