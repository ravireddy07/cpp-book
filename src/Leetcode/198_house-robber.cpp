// Problem Statement: https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result[nums.size()];
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            result[i] = max(result[i - 1], nums[i] + result[i - 2]);
        return result[nums.size() - 1];
    }
};

int main()
{
    Solution a;
    cout << a.rob({2, 1, 1, 2}) << "\n";
    return 0;
}
