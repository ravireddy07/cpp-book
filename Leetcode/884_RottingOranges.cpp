// https://leetcode.com/problems/rotting-oranges/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool valid(int n, int m, int i, int j)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        else
            return false;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (!n)
            return 0;
        int m = grid[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = -1;
        while (!que.empty())
        {
            int e = que.size();
            for (int i = 0; i < e; i++)
            {
                auto v = que.front();
                que.pop();
                int q = v.first, w = v.second;
                if (valid(n, m, q, w + 1) && grid[q][w + 1] == 1 && !vis[q][w + 1])
                {
                    que.push({q, w + 1});
                    vis[q][w + 1] = 1;
                    grid[q][w + 1] = 2;
                    cout << q << w + 1 << endl;
                }
                if (valid(n, m, q, w - 1) && grid[q][w - 1] == 1 && !vis[q][w - 1])
                {
                    que.push({q, w - 1});
                    vis[q][w - 1] = 1;
                    grid[q][w - 1] = 2;
                    cout << q << w - 1 << endl;
                }
                if (valid(n, m, q - 1, w) && grid[q - 1][w] == 1 && !vis[q - 1][w])
                {
                    que.push({q - 1, w});
                    vis[q - 1][w] = 1;
                    grid[q - 1][w] = 2;
                    cout << q - 1 << w << endl;
                }
                if (valid(n, m, q + 1, w) && grid[q + 1][w] == 1 && !vis[q + 1][w])
                {
                    que.push({q + 1, w});
                    vis[q + 1][w] = 1;
                    grid[q + 1][w] = 2;
                    cout << q + 1 << w << endl;
                }
            }
            cout << endl;
            ans++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        }
        return ans == -1 ? 0 : ans;
    }
};

int main()
{
    vector<vector<int>> input = [ [ 2, 1, 1 ], [ 1, 1, 0 ], [ 0, 1, 1 ] ];
    Soultion a;
    cout << a.orangesRotting(input) << endl;
    return 0;
}