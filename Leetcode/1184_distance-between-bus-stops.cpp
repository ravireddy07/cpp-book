// https://leetcode.com/problems/distance-between-bus-stops/

#include <iostream>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
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
    vector<int> input = {1, 2, 3, 4};
    cout << a.distanceBetweenBusStops(input, 0, 3) << endl;
    return 0;
}