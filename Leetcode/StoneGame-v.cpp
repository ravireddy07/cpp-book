#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dp[501][501];
    int dfs(vector<int> &sv, int l, int r)
    {
        if (l >= r)
            return 0;
        if (dp[l][r] >= 0)
            return dp[l][r];
        int res = 0;
        for (int i = l; i < r; ++i)
        {
            int lv = sv[i] - (l > 0 ? sv[l - 1] : 0);
            int rv = sv[r] - sv[i];
            if (lv > rv)
                res = max(res, dfs(sv, i + 1, r) + rv);
            else if (lv < rv)
                res = max(res, dfs(sv, l, i) + lv);
            else
            {
                res = max({res, dfs(sv, i + 1, r) + rv, dfs(sv, l, i) + lv});
            }
        }
        return dp[l][r] = res;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        memset(dp, -1, sizeof(dp));
        if (stoneValue.size() == 1)
            return 0;
        for (int i = 1; i < stoneValue.size(); ++i)
            stoneValue[i] += stoneValue[i - 1];
        return dfs(stoneValue, 0, stoneValue.size() - 1);
    }
};

int main()
{
    int result;
    Solution a;
    vector<int> input = {[6, 2, 3, 4, 5, 5]};
    result = a.stoneGameV(input);
    cout << result << endl;
    return 0;
}