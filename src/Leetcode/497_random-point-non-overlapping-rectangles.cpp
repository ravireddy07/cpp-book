// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> v;
    vector<vector<int>> rects;

    int area(vector<int> &r)
    {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }

    Solution(vector<vector<int>> rect)
    {
        rects = rect;
        int totalArea = 0;
        for (auto r : rects)
        {
            totalArea += area(r);
            v.push_back(totalArea);
        }
    }

    vector<int> pick()
    {
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(), v.end(), rnd) - v.begin();

        auto r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return {x, y};
    }
};