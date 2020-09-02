// https://leetcode.com/problems/minimum-time-visiting-all-points/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int time = 0;
        int n = points.size();
        if (n == 0)
            return 0;
        int cX = points[0][0];
        int cY = points[0][1];
        for (int i = 1; i < n; i++)
        {
            int aX = abs(points[i][0] - cX);
            int aY = abs(points[i][1] - cY);
            time += min(aX, aY);
            time += max(aX, aY) - min(aX, aY);
            cX = points[i][0];
            cY = points[i][1];
        }
        return time;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = [ [ 1, 1 ], [ 3, 4 ], [ -1, 0 ] ];
    cout << a.minTimeToVisitAllPoints(input) << endl;
    return 0;
}