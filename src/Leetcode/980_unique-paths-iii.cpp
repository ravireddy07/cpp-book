// https://leetcode.com/problems/unique-paths-iii/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size();
        if (!m)
            return 0;
        n = grid[0].size();
        int start = -1, end = -1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    start = i * n + j;
                else if (grid[i][j] == 2)
                    end = i * n + j;
                else if (grid[i][j] == 0)
                    ++emptySpaces;
            }
        }

        dfs(grid, start, end);
        return res;
    }

private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int m;
    int n;
    int emptySpaces = 0;
    int res = 0;
    unordered_set<int> visited;
    void dfs(vector<vector<int>> &grid, int idx, int target)
    {
        if (idx == target)
        {
            if (visited.size() == emptySpaces + 1)
                ++res;
            return;
        }

        visited.insert(idx);
        int x = idx / n, y = idx % n;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i], nn = nx * n + ny;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited.count(nn) || grid[nx][ny] == -1)
                continue;
            dfs(grid, nn, target);
        }
        visited.erase(idx);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    cout << a.uniquePathsIII(input) << endl;
    return 0;
}