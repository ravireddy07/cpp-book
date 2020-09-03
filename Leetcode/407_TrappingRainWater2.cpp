// https://leetcode.com/problems/trapping-rain-water-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &matrix)
    {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = matrix.size(), n = matrix[0].size();
        auto cmp = [&](const vector<int> &l, const vector<int> &r) {
            return matrix[l[0]][l[1]] > matrix[r[0]][r[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < n; ++i)
        {
            q.push({0, i});
            q.push({m - 1, i});
            vis[0][i] = true;
            vis[m - 1][i] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            q.push({i, 0});
            q.push({i, n - 1});
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }
        int res = 0, gMax = INT_MIN;
        while (!q.empty())
        {
            int x, y;
            auto t = q.top();
            x = t[0], y = t[1];
            q.pop();
            gMax = max(gMax, matrix[x][y]);
            for (auto d : dir)
            {
                int dx = x + d[0], dy = y + d[1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n || vis[dx][dy])
                    continue;
                if (matrix[dx][dy] < gMax)
                    res += gMax - matrix[dx][dy];
                q.push({dx, dy});
                vis[dx][dy] = true;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    cout << a.trapRainWater(input) << endl;
    return 0;
}