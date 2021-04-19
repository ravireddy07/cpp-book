// Problem Statement:  https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || '0' == grid[i][j])
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if ('1' == grid[i][j])
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{"1", "1", "1", "1", "0"},
                                 {"1", "1", "0", "1", "0"},
                                 {"1", "1", "0", "0", "0"},
                                 {"0", "0", "0", "0", "0"}};
    cout << a.numIslands(input) << "\n";
    return 0;
}
