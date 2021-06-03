// Problem Statement: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> c;
    vector<int> ps;

    Solution(vector<vector<int>> &rects)
    {
        c = rects;
        int n = c.size();
        ps = vector<int>(n); //creating a prefix sum of areas vector

        for (int i = 0; i < n; i++)
        {
            int area = (c[i][2] - c[i][0] + 1) * (c[i][3] - c[i][1] + 1);
            if (i != 0)
                ps[i] = ps[i - 1];
            ps[i] += area;
        }
    }

    vector<int> pick()
    {
        int rs = rand() % (ps.back()) + 1; //selecting a rectangle based on their area distribution
        int idx = lower_bound(ps.begin(), ps.end(), rs) - ps.begin();

        int d1 = c[idx][2] - c[idx][0] + 1;
        int x = c[idx][0] + rand() % d1; //randomly selecting its x-coordinate
        int d2 = c[idx][3] - c[idx][1] + 1;
        int y = c[idx][1] + rand() % d2; //randomly selecting its x-coordinate

        return {x, y};
    }
};

int main()
{
    Solution a{"Solution", "pick", "pick", "pick"} {{{{1, 1, 5, 5}}}, {}, {}, {}};
    cout << a.pick() << "\n";
    return 0;
}
