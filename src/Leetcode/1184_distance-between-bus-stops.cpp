// Problem Statement: https://leetcode.com/problems/distance-between-bus-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> distance, int start, int destination)
    {
        int sum1 = 0, sum2 = 0;
        int i = start;
        while (i != destination)
        {
            if (i >= distance.size())
            {
                i = 0;
                continue;
            }
            sum1 += distance[i];
            i++;
        }
        i = destination;
        while (i != start)
        {
            if (i >= distance.size())
            {
                i = 0;
                continue;
            }
            sum2 += distance[i];
            i++;
        }
        return min(sum1, sum2);
    }
};

int main()
{
    Solution a;
    cout << a.distanceBetweenBusStops({1, 2, 3, 4}, 0, 3) << "\n";
    return 0;
}
