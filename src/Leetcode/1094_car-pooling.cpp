// https://leetcode.com/problems/car-pooling/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        map<int, int> record;
        for (const auto &trip : trips)
        {
            record[trip[1]] += trip[0];
            record[trip[2]] -= trip[0];
        }
        for (const auto &r : record)
        {
            if ((capacity -= r.second) < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{2, 1, 5}, {3, 3, 7}};
    cout << a.carPooling(input, 4) << endl;
    return 0;
}