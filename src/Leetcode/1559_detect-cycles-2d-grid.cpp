// https://leetcode.com/problems/detect-cycles-in-2d-grid/
// https://leetcode.com/problems/detect-cycles-in-2d-grid/discuss/806106/Best-MethodProcess-using-DFS-or-Top-80-in-Run-Time-or-O(mn)-Complexity

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    const vector<vector<int>> possibleD = {{0, 1},
                                           {1, 0},
                                           {-1, 0},
                                           {0, -1}}; //Possible Directions
    int m, n;                                        //Grid Size

public:
    bool dfs(vector<vector<char>> &grid, int i, int j, char c, int dir)
    {
        if (i < 0 || i >= n || j < 0 || j >= m) // Checking borders
            return false;
        if (grid[i][j] == '0') // Checking for Cycle
            return true;
        if (grid[i][j] != c)
            return false;

        grid[i][j] = '0';           // Marking current cell
        dir = 3 - dir;              // This is for not to traversing back/re-visit.
        for (int k = 0; k < 4; ++k) // Traversing all other three direction(which are not visited yet)
        {
            if (k != dir) // Unwanted/Visited direction
                if (dfs(grid, i + possibleD[k][0], j + possibleD[k][1], c, k))
                    return true;
        }
        grid[i][j] = ' ';
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid[0].size();
        n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] != ' ')
                    if (dfs(grid, i, j, grid[i][j], -1))
                        return true;
        return false;
    }
};

int main()
{
    Solution a;
    vector<vector<char>> input = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}};
    bool result = a.containsCycle(input);
    cout << (bool)result << endl;
    return 0;
}