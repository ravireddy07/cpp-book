// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> pq;
        pq.push({startFuel});
        int dist = 0;
        int answer = 0;
        int i = 0;
        while (!pq.empty() && dist < target)
        {
            dist += pq.top();
            pq.pop();
            answer++;
            while (i < stations.size() && stations[i][0] <= dist)
            {
                pq.push(stations[i][1]);
                i++;
            }
        }
        if (dist < target)
            return -1;
        return answer - 1;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << a.minRefuelStops(100, 10, input) << endl;
    return 0;
}