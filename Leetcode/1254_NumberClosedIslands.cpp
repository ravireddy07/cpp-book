// https://leetcode.com/problems/number-of-closed-islands/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int x, int y, bool &flag)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
        {
            flag = false;
            return;
        }
        if (grid[x][y] == 1)
            return;

        grid[x][y] = 1;
        dfs(grid, x + 1, y, flag);
        dfs(grid, x, y + 1, flag);
        dfs(grid, x - 1, y, flag);
        dfs(grid, x, y - 1, flag);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool flag = true;
                if (grid[i][j] == 0)
                {
                    dfs(grid, i, j, flag);
                    if (flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = [ [ 1, 1, 1, 1, 1, 1, 1, 0 ],
                          [ 1, 0, 0, 0, 0, 1, 1, 0 ],
                          [ 1, 0, 1, 0, 1, 1, 1, 0 ],
                          [ 1, 0, 0, 0, 0, 1, 0, 1 ],
                          [ 1, 1, 1, 1, 1, 1, 1, 0 ] ];
    cout << a.closedIsland(input) << endl;
    return 0;
}