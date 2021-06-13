// Problem Statement: https://leetcode.com/problems/valid-square/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // helper function to calculate distance between two points
    double dist(vector<int> p1, vector<int> p2)
    {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }

    bool validSquare(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4)
    {
        // keep points in an array to be able to get them by index
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> lengths;

        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                double curr = dist(points[i], points[j]);
                if (curr != 0)
                    lengths.insert(curr);

                // if distance is zero - we got a duplicated point
                else
                    return false;
            }
        }
        // We are supposed to end with only two different lengths: the sides and the diagonals
        return lengths.size() == 2;
    }
};

int main()
{
    Solution a;
    cout << a.validSquare({0, 0}, {1, 1}, {0, 1}, {1, 0}) << "\n";
    return 0;
}
