// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int check(vector<vector<int>> &mat, int row, int col)
    {
        int res = 1;
        /* Checking Column by Traversing each Row */
        for (int i = 0; i < mat.size(); ++i)
            // If anyone of the row having 1, then it's not Special
            if (mat[i][col] != 0)
                if (i != row)
                    // If any of the index, matrix having 1, then it's not special
                    res = 0;

        /* Checking Row by Traversing each Column */
        for (int i = 0; i < mat[0].size(); ++i)
            // If anyone of the column having 1, then it's not Special
            if (mat[row][i] != 0)
                if (i != col)
                    // If any of the index, matrix having 1, then it's not special
                    res = 0;
        return res;
    }

    int numSpecial(vector<vector<int>> &mat)
    {
        int count = 0;
        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                if (mat[i][j] == 1)
                    // Checking wheither this row & column has only this single 1 or not
                    count += check(mat, i, j);
        return count;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    cout << a.numSpecial(input) << endl;
    return 0;
}