// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == target)
                    return true;
                else if (matrix[i][j] > target)
                    return false;
            }
        }
        return false;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> in = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    cout << a.searchMatrix(in, 13) << endl;
    return 0;
}