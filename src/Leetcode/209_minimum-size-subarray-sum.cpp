// Problem Statement: https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> nums)
    {
        if (nums.size() == 0)
            return 0;
        int res = INT_MAX, sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= s)
                return 1;
            sum = nums[i];
            count = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (sum + nums[j] >= s)
                {
                    sum += nums[j];
                    count++;
                    break;
                }
                else if (sum + nums[j] < s)
                {
                    sum += nums[j];
                    count++;
                }
            }

            if (sum >= s && count < res && count != 1)
                res = count;
        }
        return (res == INT_MAX ? 0 : res);
    }
};

int main()
{
    Solution a;
    cout << a.minSubArrayLen(11, {1, 2, 3, 4, 5}) << "\n";
    return 0;
}
