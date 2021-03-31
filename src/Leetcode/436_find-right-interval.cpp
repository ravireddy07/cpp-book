// Problem Statement: https://leetcode.com/problems/find-right-interval/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for (int i = 0; i < intervals.size(); i++)
            ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
        return ans;
    }
};

int main()
{
    vector<vector<int>> input = {{3, 4}, {2, 3}, {1, 2}};
    Solution a;
    vector<int> show = a.findRightInterval(input);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}
