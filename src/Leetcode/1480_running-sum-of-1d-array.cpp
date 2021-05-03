// Problem Statement: https://leetcode.com/problems/running-sum-of-1d-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        return nums;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3, 4};
    vector<int> show = a.runningSum(input);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]"
         << "\n";
    return 0;
}
