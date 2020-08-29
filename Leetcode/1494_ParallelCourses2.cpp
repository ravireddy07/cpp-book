// https://leetcode.com/problems/parallel-courses-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> graph[20];
    int dp[(1 << 15) + 1], N, maxSub;

    vector<int> getIndegFromMask(int mask)
    {
        vector<int> indeg(N, 0);
        for (int i = 0; i < N; ++i)
        {
            if (!(mask & (1 << i)))
            {
                for (int j = 0; j < graph[i].size(); ++j)
                {
                    int v = graph[i][j];
                    indeg[v]++;
                }
            }
        }
        return indeg;
    }

    int countSetBits(int mask)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
            {
                cnt++;
            }
        }
        return cnt;
    }

    int setBitsWithDegZero(vector<int> indeg, int mask)
    {
        int x = 0;
        for (int i = 0; i < N; ++i)
        {
            if (indeg[i] == 0 && !(mask & (1 << i)))
            {
                x |= (1 << i);
            }
        }
        return x;
    }

    int solve(int mask)
    {
        if (mask == (1 << N) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        vector<int> indeg = getIndegFromMask(mask);
        int eligibleMask = setBitsWithDegZero(indeg, mask);
        int validSubjectsCnt = countSetBits(eligibleMask);

        if (validSubjectsCnt <= maxSub)
        {
            return dp[mask] = 1 + solve(mask | eligibleMask);
        }
        else
        {
            int ans = N;
            // traverse through all sub-masks of mask such that only k subjects are selected
            for (int s = eligibleMask; s > 0; s = eligibleMask & (s - 1))
            {
                if (maxSub == countSetBits(s))
                {
                    ans = min(ans, 1 + solve(mask | s));
                }
            }
            return dp[mask] = ans;
        }
    }

    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
    {
        N = n;
        maxSub = k;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < dependencies.size(); ++i)
        {
            graph[dependencies[i][0] - 1].push_back(dependencies[i][1] - 1);
        }
        return solve(0);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> dependencies = [ [ 2, 1 ], [ 3, 1 ], [ 4, 1 ], [ 1, 5 ] ];
    cout << a.minNumberOfSemesters(2, dependencies, 2) << endl;
    return 0;
}