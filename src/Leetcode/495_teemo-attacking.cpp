// Problem Statement: https://leetcode.com/problems/teemo-attacking/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> timeSeries, int duration)
    {
        if (timeSeries.size() == 0)
            return 0;
        int res = duration;
        for (int i = 1; i < timeSeries.size(); ++i)
        {
            if (duration <= timeSeries[i] - timeSeries[i - 1])
                res += duration;
            else
                res += timeSeries[i] - timeSeries[i - 1];
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.findPoisonedDuration({1, 4}, 2) << "\n";
    return 0;
}
