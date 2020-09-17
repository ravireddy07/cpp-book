// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSub = nums[0], curSum = 0;

        for (int n : nums)
        {
            if (curSum < 0)
                curSum = 0;
            curSum += n;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};

int main()
{
    Solution a;
    vector<int> input = [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ];
    cout << a.maxSubArray(input) << endl;
    return 0;
}
