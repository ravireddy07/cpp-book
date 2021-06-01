// Problem Statement: https://leetcode.com/problems/assign-cookies/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> g, vector<int> s)
    {
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size() and j < g.size();)
        {
            if (s[i] >= g[j])
            {
                result++;
                j++;
            }
            i++;
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.findContentChildren({1, 2, 3}, {1, 1}) << "\n";
    return 0;
}
