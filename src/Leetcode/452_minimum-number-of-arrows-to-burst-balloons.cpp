// Problem Statement: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> points)
    {
        sort(points.begin(), points.end());
        stack<pair<int, int>> S;
        S.push({points[0][0], points[0][1]});

        for (int i = 1; i < points.size(); i++)
        {
            int currX = points[i][0];
            int currY = points[i][1];
            if (currX >= S.top().first and currX <= S.top().second)
            {
                int updateX = max(S.top().first, currX);
                int updateY = min(S.top().second, currY);
                S.pop();
                S.push({updateX, updateY});
            }
            else
                S.push({currX, currY});
        }
        return S.size();
    }
};

int main()
{
    Solution a;
    cout << a.findMinArrowShots({{10, 16}, {2, 8}, {1, 6}, {7, 12}}) << "\n";
    return 0;
}
