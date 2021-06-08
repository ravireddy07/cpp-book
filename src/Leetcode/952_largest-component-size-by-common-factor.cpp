// Problem Statement: https://leetcode.com/problems/largest-component-size-by-common-factor/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int parent[100001];
    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool uni(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp)
            parent[yp] = xp;
        else
            return false;
        return true;
    }
    int largestComponentSize(vector<int> arr)
    {
        unordered_map<int, int> memo;
        memset(parent, -1, sizeof(parent));
        int ret = 0;
        for (int x : arr)
        {
            int flag = 0;
            for (int i = 2; i * i <= x; ++i)
                if (x % i == 0)
                {
                    uni(i, x);
                    uni(x, x / i);
                    flag = 1;
                }
        }
        for (int x : arr)
            ret = max(ret, ++memo[find(x)]);
        return ret;
    }
};

int main()
{
    Solution a;
    cout << a.largestComponentSize({2, 3, 6, 7, 4, 12, 21, 39}) << "\n";
    return 0;
}
