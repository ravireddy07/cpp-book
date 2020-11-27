// https://leetcode.com/problems/as-far-from-land-as-possible/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int N = grid.size();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        if (q.empty() || q.size() == N * N)
            return -1;
        int count = -1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r - 1 >= 0 && grid[r - 1][c] == 0)
                {
                    q.push({r - 1, c});
                    grid[r - 1][c] = 1;
                }
                if (r + 1 < N && grid[r + 1][c] == 0)
                {
                    q.push({r + 1, c});
                    grid[r + 1][c] = 1;
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 0)
                {
                    q.push({r, c - 1});
                    grid[r][c - 1] = 1;
                }
                if (c + 1 < N && grid[r][c + 1] == 0)
                {
                    q.push({r, c + 1});
                    grid[r][c + 1] = 1;
                }
            }
            count++;
        }
        return count;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << a.maxDistance(input) << endl;
    return 0;
}
