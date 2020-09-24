// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = grid.size() - 1; i >= 0; i--)
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (grid[i][j] < 0)
                    res++;
                else
                    break;
            }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << a.countNegatives(input) << endl;
    return 0;
}