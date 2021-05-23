// Problem Statement: https://leetcode.com/problems/gas-station/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> gas, vector<int> cost)
    {
        int n = gas.size();
        int prevSum = 0;
        int j = 0;
        for (int start = 0; start < n; start++)
        {
            int sum = 0;
            while (j < n and sum >= 0)
            {
                sum += gas[j] - cost[j];
                j++;
            }
            prevSum += sum;
            if (prevSum >= 0 and j == n)
                return start;
            start = j - 1;
        }
        return -1;
    };
};

int main()
{
    Solution a;
    cout << a.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) << "\n";
    return 0;
}
