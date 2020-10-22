// https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int par[1001];

    void init()
    {
        for (int i = 1; i <= 1000; i++)
            par[i] = i;
    }

    int find(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = find(par[node]);
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            par[b] = a;
    }

    int minCostConnectPoints(vector<vector<int>> &p)
    {
        init();
        int n = p.size();
        vector<pair<int, pair<int, int>>> a;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                a.push_back({(abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1])), {i, j}});

        sort(a.begin(), a.end());
        int ans = 0;
        for (auto x : a)
        {
            int ax = x.second.first, ay = x.second.second;
            if (find(ax) != find(ay))
            {
                ans += x.first;
                merge(ax, ay);
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << a.minCostConnectPoints(input) << endl;
    return 0;
}